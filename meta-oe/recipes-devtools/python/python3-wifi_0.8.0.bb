SUMMARY = "Command line tool and library wrappers around iwlist and /etc/network/interfaces."
HOMEPAGE = "https://pypi.org/project/wifi/"
SECTION = "devel/python"
LICENSE = "LGPLv2+ & GPLv2+"
LIC_FILES_CHKSUM = "file://LICENSE;md5=96054b336a7ea61f1acd5c14acdda526"

RDEPENDS:${PN} = "${PYTHON_PN}-pbkdf2"

SRC_URI = "git://github.com/oe-mirrors/wifi.git"

SRCREV ?= "ea9b8896d9866ac752b60f87e767d2a9565d00cb"

inherit setuptools3

S = "${WORKDIR}/git"

include ${PYTHON_PN}-package-split.inc
