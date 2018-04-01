include(version.pri)
TEMPLATE = subdirs
CONFIG += ordered
SUBDIRS += lib tests

dox.target = doc
dox.commands = sed 's/@VERSION@/'$$VERSION'/' doxygen.cfg.in > doxygen.cfg; \
               doxygen doxygen.cfg
dox.path = $$[QT_INSTALL_PREFIX]/share/doc/ofono-qt
dox.files = doc/html
dox.CONFIG = no_link
dox.depends = FORCE
dox.clean_commands = rm -fr doc/
dox.clean = doxygen.cfg 

INSTALLS += dox

QMAKE_EXTRA_TARGETS += dox

