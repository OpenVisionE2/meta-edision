KV = "5.12.0"
SRCDATE = "20210601"

MODNAMES = "brcmstb-${MACHINE} brcmstb-decoder ci avl6261 avl6862 si2183"

require os-dvb-modules.inc

COMPATIBLE_MACHINE = "^(osmio4k)$"

SRC_URI[md5sum] = "3bfde48fdc9f83100aa6729f5fd32942"
SRC_URI[sha256sum] = "0a64d4d32183a2e304c288cfdd8dbb0ef6002815a6bfdf2b98e633f63b03cbbe"
