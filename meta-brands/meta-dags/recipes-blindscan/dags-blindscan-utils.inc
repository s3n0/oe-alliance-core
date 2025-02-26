DESCRIPTION = "Utils for blindscan"
SECTION = "base"
PRIORITY = "optional"
LICENSE = "CLOSED"

PACKAGES = "dags-blindscan-utils-${SOC_FAMILY}"

PROVIDES += "virtual/blindscan-dvbs"
RPROVIDES:dags-blindscan-utils-${SOC_FAMILY} += "virtual/blindscan-dvbs"

PV = "1.0"
PR = "r0"

SRC_URI = "http://en3homeftp.net/pub/down/dags_blindscan_${SOC_FAMILY}.tar.gz"

S = "${WORKDIR}"

INHIBIT_PACKAGE_STRIP = "1"

PACKAGE_ARCH := "${MACHINE_ARCH}"

