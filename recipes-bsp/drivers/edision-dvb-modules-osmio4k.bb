KV = "5.5.9"
SRCDATE = "20200313"
MODNAMES = "brcmstb-${MACHINE} ci avl6261 avl6862 si2183"

require os-dvb-modules.inc

COMPATIBLE_MACHINE = "^(osmio4k)$"

SRC_URI[md5sum] = "ac4fe2f1cc2460a6d318cb78a92a2650"
SRC_URI[sha256sum] = "c9edcf90ec02696bd1a2f09266cd9c11cd34b1ac50311321a54595a02f4947dc"
SRC_URI[arm64.md5sum] = "ac4fe2f1cc2460a6d318cb78a92a2650"
SRC_URI[arm64.sha256sum] = "c9edcf90ec02696bd1a2f09266cd9c11cd34b1ac50311321a54595a02f4947dc"
