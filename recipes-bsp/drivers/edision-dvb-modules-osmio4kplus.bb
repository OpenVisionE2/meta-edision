KV = "5.5.9"
SRCDATE = "20200313"
MODNAMES = "brcmstb-${MACHINE} ci si2183 avl6862 avl6261"

require os-dvb-modules.inc

COMPATIBLE_MACHINE = "^(osmio4kplus)$"

SRC_URI[md5sum] = "b199f1c07692ce10e43a5859329ad284"
SRC_URI[sha256sum] = "46c15f8457631ef97b47d456c1424b690da0ff55a112fafbea1e6ca1bba345b2"
SRC_URI[arm64.md5sum] = "b199f1c07692ce10e43a5859329ad284"
SRC_URI[arm64.sha256sum] = "46c15f8457631ef97b47d456c1424b690da0ff55a112fafbea1e6ca1bba345b2"
