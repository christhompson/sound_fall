import os, os.path, sys, time

import pyopenal

pyopenal.init(None)
l = pyopenal.Listener(22050)
l.position = (0.0, 0.0, 0.0)
l.at = (0.0, 0.0, 1.0)
l.up = (0.0, 1.0, 0.0)

b = pyopenal.WaveBuffer(os.path.join(os.path.dirname(sys.argv[0]), "sword.wav"))
#b = pyopenal.OggVorbisBuffer("/home/jiba/src/slune/sounds/summum_of_the_light.ogg")

s = pyopenal.Source()
s.position = (0.0, 0.0, 0.0)
s.velocity = (0.0, 0.0, 0.0)
s.buffer  = b
s.looping = 1

s.play()

# Move the source further

z = 0.0
i = 0
while i < 100:
  z += 0.5
  s.position = (0.0, 0.0, z)
  time.sleep(0.1)
  i = i + 1

print 'ok'


## device = openal.alcOpenDevice(None)
## #device = openal.alcOpenDevice("'( ( devices '( native waveout esd sdl alsa arts null ) ) )")
## context = openal.alcCreateContext (device, (openal.ALC_FREQUENCY, 22050, openal.ALC_INVALID))
## openal.alcMakeContextCurrent (context)


## openal.alListenerfv (openal.AL_POSITION, (0.0, 0.0, 0.0))
## openal.alListenerfv (openal.AL_ORIENTATION, (0.0, 0.0, 1.0, 0.0, 1.0, 0.0))
## stereo = openal.alGenBuffers (1)

## file = open('./sword.wav', 'r')
## data = file.read()
## openal.alBufferData (stereo, openal.AL_FORMAT_WAVE_EXT, data, 0)
## moving_source = openal.alGenSources (1)
     
## openal.alSource3f (moving_source, openal.AL_POSITION, 0.0, 0.0, 20.0)
## openal.alSourcefv (moving_source, openal.AL_VELOCITY, (0.0, 0.0, 0.0))
## openal.alSourcei  (moving_source, openal.AL_BUFFER, stereo)
## openal.alSourcei  (moving_source, openal.AL_LOOPING, openal.AL_FALSE)
   
## openal.alSourcePlayv (moving_source)
## #openal.alSourcei (moving_source, openal.AL_SOURCE_STATE, openal.AL_INITIAL)

## print "Using OpenAL", openal.alGetString(openal.AL_VERSION), "by", openal.alGetString(openal.AL_VENDOR)

## while(1): pass
