KV = "5.12.0"
SRCDATE = "20210524"

MODNAMES = "brcmstb-${MACHINE} brcmstb-decoder ci avl6261 avl6862 si2183"

require os-dvb-modules.inc

COMPATIBLE_MACHINE = "^(osmio4k)$"

SRC_URI[md5sum] = "8c4fbfbb04cef9862ce9690b564b4576"
SRC_URI[sha256sum] = "36d2a6277db8580ea2a68537d7e3eb2ed88783eea1c823c86b1eb33074dddc05"
