inherit upx-compress

EXTRA_OECONF += "--enable-defrag"

do_install:append() {
	if [ -e ${D}${base_sbindir}/e4defrag ]; then
		install -d ${D}${sbindir}
		mv ${D}${base_sbindir}/e4defrag ${D}${sbindir}/e4defrag
	fi
}

PACKAGES =+ "e2fsprogs-e4defrag"
FILES:e2fsprogs-e4defrag = "/usr/sbin/e4defrag"

