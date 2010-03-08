import os
from distutils.core import setup, Extension

LIBDIRS = ["/usr/lib", "/usr/local/lib"]
LIBS    = ["openal", "alut"]

try:
  openal_version = os.popen("openal-config --version").read()
  if openal_version[0] == "0":
    LIBDIRS = ["/usr/lib", "/usr/local/lib"]
    LIBS    = ["openal"]
    
except:
  print "Warning: error while running 'openal-config --version', using default values..."


setup(
  name         = "PyOpenAL",
  version      = "0.1.6",
  license      = "LGPL",
  description  = "OpenAL port to Python.",
  long_description  = """OpenAL port to Python.
Does not include OpenAL extension.""",
  author       = "Blam (LAMY Bertrand), Jiba (LAMY Jean-Baptiste)",
  author_email = "jibalamy@free.fr",
  url          = "http://home.gna.org/oomadness/en/pyopenal/index.html",
  classifiers  = [
  "Topic :: Multimedia :: Sound/Audio :: Players",
  "Topic :: Software Development :: Libraries :: Python Modules",
  "Programming Language :: Python",
  "Intended Audience :: Developers",
  "Development Status :: 5 - Production/Stable",
  "License :: OSI Approved :: GNU Library or Lesser General Public License (LGPL)",
  ],
  
  package_dir  = {"pyopenal" : ""},
  packages     = ["pyopenal"],
  
  ext_modules  = [Extension("_openal",
                            ["py_openal.c"],
                            ["/usr/include", "/usr/local/include"],
                            [("HAVE_CONFIG_H", None)],
                            None,
                            LIBDIRS,
                            LIBS,
                            )
                  ]
  )

