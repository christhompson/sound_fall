# PyOpenAl
# Copyright (C) 2003 Jean-Baptiste LAMY -- jiba@tuxfamily.org
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

"""pyopenal

OpenAL binding for Python.

File formats supported:
 - Wave
 - Ogg Vorbis (needs PyOgg and PyVorbis)

The binding does not include yet OpenAL extensions.

See test.py for an example."""

from _openal import *
import _openal

from cStringIO import StringIO

import atexit
atexit.register(quit)

_INITED = 0
def init(arg = "'( ( devices '( native esd sdl alsa arts null ) ) )"):
  """init(arg = "'( ( devices '( native esd sdl alsa arts null ) ) )"

Inits OpenAL. ARG can be used to select which device to use."""
  global _INITED
  if not _INITED:
    _openal.init(arg)
    _INITED = 1

class Listener(_openal._Listener):
  """Listener

A listener that listens sounds."""
  pass

class Source(_openal._Source):
  """Source

A source that produces sound."""
  pass

Buffer = _openal._Buffer
# class Buffer(_openal._Buffer):
#   def __init__(self, format = None, data = None, freq = 0):
#     _openal._Buffer.__init__(self)
#     if not format is None:
#       self.set_data(format, data, freq)


def wave_data(filename):
  """wave_data(filename) -> format, data, freq

Get the data from a Wave file, in a format suitable for Buffer.set_data."""
  
  import wave
  wav  = wave.open(filename)
  data = wav.readframes(wav.getnframes())
  
  if wav.getnchannels() == 2:
    if wav.getsampwidth() == 2: return AL_FORMAT_STEREO16, data, wav.getframerate()
    else:                       return AL_FORMAT_STEREO8 , data, wav.getframerate()
  else:
    if wav.getsampwidth() == 2: return AL_FORMAT_MONO16  , data, wav.getframerate()
    else:                       return AL_FORMAT_MONO8   , data, wav.getframerate()
    
def ogg_vorbis_data(filename):
  """ogg_vorbis_data(filename) -> format, data, freq

Get the data from an Ogg Vorbis file, in a format suitable for Buffer.set_data.
Require PyOgg and PyVorbis"""
  
  import ogg.vorbis
  vorb = ogg.vorbis.VorbisFile(filename)
  info = vorb.info()
  
  buffer = Buffer()
  
  bytes = 1
  data  = StringIO()
  while bytes:
    buff, bytes, bit = vorb.read(4096)
    data.write(buff[:bytes])
  data = data.getvalue()
  
  # Assume Ogg Vorbis file are 16 bit sounds !!!
  # XXX I'm not sure of that !!!
  
  if info.channels == 2: return AL_FORMAT_STEREO16, data, info.rate 
  else:                  return AL_FORMAT_MONO16  , data, info.rate 


def WaveBuffer(filename):
  """WaveBuffer(filename) -> Buffer

Loads a Wave file, for playing with OpenAL."""
  buffer = Buffer()
  buffer.set_data(*wave_data(filename))
  return buffer

def OggVorbisBuffer(filename):
  """OggVorbisBuffer(filename) -> Buffer

Loads an Ogg Vorbis file, for playing with OpenAL.
Require PyOgg and PyVorbis"""
  
  buffer = Buffer()
  buffer.set_data(*ogg_vorbis_data(filename))
  return buffer
  
