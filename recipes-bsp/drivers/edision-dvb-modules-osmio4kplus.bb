KV = "5.12.0"
SRCDATE = "20210601"

MODNAMES = "brcmstb-${MACHINE} brcmstb-decoder ci si2183 avl6862 avl6261"

require os-dvb-modules.inc

COMPATIBLE_MACHINE = "^(osmio4kplus)$"

SRC_URI[md5sum] = "124a99e4a4b4799f7f537d47153f15d9"
SRC_URI[sha256sum] = "e09abeed4d8986804afd6fd0b5b3f8fa14fd255d132c0a22a6aaf309b96ab4a6"
