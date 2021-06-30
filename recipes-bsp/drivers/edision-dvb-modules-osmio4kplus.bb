KV = "5.13.0"
SRCDATE = "20210629"

MODNAMES = "brcmstb-${MACHINE} brcmstb-decoder ci si2183 avl6862 avl6261"

require os-dvb-modules.inc

COMPATIBLE_MACHINE = "^(osmio4kplus)$"

SRC_URI[md5sum] = "97262c8f0e5996b1ca7f8bb037369cab"
SRC_URI[sha256sum] = "adf89039519a0723e26ee796437d7770f55bcce894980be2ab6ff6759ca8f009"
