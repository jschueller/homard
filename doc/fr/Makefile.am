# Copyright (C) 2011-2013  CEA/DEN, EDF R&D
#
# This library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 2.1 of the License.
#
# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public
# License along with this library; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
#
# See http://www.salome-platform.org/ or email : webmaster.salome@opencascade.com
#

homarddoc_langue=fr
#
include $(top_srcdir)/adm_local/unix/make_common_starter.am

if SPHINX_IS_OK

homarddoc_DATA=html/index.html
html/index.html:$(RSTFILES) dummy

dummy:
	make htm
	make latex

endif

homarddocdir=$(docdir)/gui/HOMARD/$(homarddoc_langue)

SPHINXOPTS  =
SPHINXBUILD = sphinx-build

htm:
#	mkdir -p html doctrees
	mkdir -p html
	$(SPHINXBUILD) $(SPHINXOPTS) -c $(top_builddir)/doc/$(homarddoc_langue) -b html $(srcdir) html
	@echo
	@echo "Build fini. Les pages HTML sont dans html."

latex:
#	mkdir -p latex doctrees
	mkdir -p latex
	$(SPHINXBUILD) $(SPHINXOPTS) -c $(top_builddir)/doc/$(homarddoc_langue) -b latex $(srcdir) latex
	@echo
	@echo "Build fini. Les pages sont en latex."
	@echo "Aller dans latex et appliquer deux fois : pdflatex HOMARD.tex pour produire HOMARD.pdf"

RSTFILES= \
index.rst \
glossaire.rst \
gui_create_boundary.rst \
gui_create_case.rst \
gui_create_hypothese.rst \
gui_create_iteration.rst \
gui_create_zone.rst \
gui_homard.rst \
gui_usage.rst \
gui_mesh_info.rst \
intro.rst \
tui_create_boundary.rst \
tui_create_case.rst \
tui_create_hypothese.rst \
tui_create_iteration.rst \
tui_create_zone.rst \
tui_homard.rst \
tui_usage.rst \
tutorials.rst \
gui_create_yacs.rst \
gui_create_yacs_aster.rst \
tui_create_yacs.rst

EXTRA_DIST += $(RSTFILES) images ../images ../files

usr_docs:
	make install-data-local

docs: usr_docs

install-data-local:
	$(INSTALL) -d $(DESTDIR)$(homarddocdir)
	if test -d "html"; then b=; else b="$(srcdir)/"; fi; \
	if test -d $$b"html"; then cp -rf $$b"html"/* $(DESTDIR)$(homarddocdir); fi;

uninstall-local:
	chmod -R +w $(DESTDIR)$(homarddocdir)
	rm -rf $(DESTDIR)$(homarddocdir)/*

clean-local:
	-rm -rf doctrees
	if test -d "html"; then rm -rf html ; fi
	if test -d "latex"; then rm -rf latex ; fi

dist-hook:
	if test -d "html"; then b=; else b="$(srcdir)/"; fi; \
	if test -d $$b"html"; then cp -rf $$b"html" $(distdir) ; fi
