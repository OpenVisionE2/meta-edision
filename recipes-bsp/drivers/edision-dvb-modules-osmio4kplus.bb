KV = "5.9.0"
SRCDATE = "20210323"

MODNAMES = "brcmstb-${MACHINE} brcmstb-decoder ci si2183 avl6862 avl6261"

require os-dvb-modules.inc

COMPATIBLE_MACHINE = "^(osmio4kplus)$"

SRC_URI[md5sum] = "fed32e2e26aa18c972e61c3a75018610"
SRC_URI[sha256sum] = "cc90fa21319a83a69cfab61e2508426b802e5b92766fa5d225ca989079f6b71e"
