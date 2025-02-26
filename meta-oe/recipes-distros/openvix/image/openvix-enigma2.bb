SUMMARY = "OpenViX Enigma2"
MAINTAINER = "OpenViX"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302 \
                    file://${COREBASE}/meta/COPYING.MIT;md5=3da9cfbcb788c80a0384361b4de20420"

ALLOW_EMPTY:${PN} = "1"
PACKAGES = "${PN}"

PV = "${IMAGE_VERSION}"
PR = "r22"

inherit packagegroup

RCONFLICTS:${PN} = "enigma2-plugin-extensions-permanenttimeshift enigma2-plugin-systemplugins-skinselector"
RREPLACES:${PN} = "enigma2-plugin-extensions-permanenttimeshift enigma2-plugin-systemplugins-skinselector"

RDEPENDS:${PN} = "\
    enigma2-skindefault \
    openvix-core \
    "

RRECOMMENDS:${PN} = "\
    enigma-kernel-module \
    enigma2-plugin-extensions-autotimer \
    enigma2-plugin-extensions-epgimport \
    enigma2-plugin-extensions-epgsearch \
    enigma2-plugin-extensions-openwebif-webtv \
    enigma2-plugin-extensions-imdb \
    enigma2-plugin-extensions-openwebif-themes \
    enigma2-plugin-extensions-openwebif-vxg \
    enigma2-plugin-skins-openvix-magic-fhd \
    enigma2-plugin-skins-openvix-simple-ten-eighty \
    enigma2-plugin-skins-openvix-vix-day-hd \
    enigma2-plugin-skins-openvix-youvix-blue \
    enigma2-plugin-systemplugins-aboutboxbranding \
    enigma2-plugin-systemplugins-opentvzapper \
    enigma2-plugin-systemplugins-xmlupdate \
    ${@bb.utils.contains("MACHINE_FEATURES", "uianimation", "enigma2-plugin-systemplugins-animationsetup" , "", d)} \
    ${@bb.utils.contains("MACHINE_FEATURES", "osdanimation", "enigma2-plugin-systemplugins-animationsetup" , "", d)} \
    ${@bb.utils.contains("MACHINE_FEATURES", "webkithbbtv", "enigma2-plugin-extensions-webkithbbtv", "", d)} \
    ${@bb.utils.contains("MACHINE_FEATURES", "quadpip", "enigma2-plugin-systemplugins-quadpip", "", d)} \
    openvix-picon-feed-opkg-conf \
    "

RRECOMMENDS:${PN}:append:et8500 = " enigma2-plugin-extensions-yahooweather"
RRECOMMENDS:${PN}:append:tmnanoseplus = " enigma2-plugin-systemplugins-tempfancontrol"
RRECOMMENDS:${PN}:append:tmnanosem2 = " enigma2-plugin-systemplugins-tempfancontrol"
RRECOMMENDS:${PN}:append:tmnanosem2plus = " enigma2-plugin-systemplugins-tempfancontrol"
RRECOMMENDS:${PN}:append:tmtwin4k = " enigma2-plugin-systemplugins-tempfancontrol"
RRECOMMENDS:${PN}:append:osmio4k = " enigma2-plugin-extensions-hbbtv-webkit"
RRECOMMENDS:${PN}:append:osmio4kplus = " enigma2-plugin-extensions-hbbtv-webkit"
RRECOMMENDS:${PN}:append:osmini4k = " enigma2-plugin-extensions-hbbtv-webkit"
