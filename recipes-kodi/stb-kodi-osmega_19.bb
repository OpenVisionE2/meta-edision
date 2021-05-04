require recipes-mediacenter/kodi/stb-kodi_${PV}.bb

PROVIDES += "virtual/kodi"
RPROVIDES_${PN} += "virtual/kodi"
PROVIDES += "kodi"
RPROVIDES_${PN} += "kodi"

EXTRA_OECMAKE += " \
    -DWITH_PLATFORM=xcore-mipsel \
    -DWITH_FFMPEG=stb \
"

COMPATIBLE_MACHINE = "^(osmega)$"
