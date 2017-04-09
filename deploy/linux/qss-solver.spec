Name: qss-solver		
Version: 3.1	
Release:	1%{?dist}
Summary: The QSS Solver is a modeling and simulation environment for continuous and hybrid systems.	

License: GPLv3	
URL:	https://sourceforge.net/projects/qssengine/	

AutoReqProv: no

Requires: /bin/bash libQtCore.so.4()(64bit) libQtGui.so.4()(64bit) libc.so.6()(64bit) libc.so.6(GLIBC_2.14)(64bit) libc.so.6(GLIBC_2.2.5)(64bit) libc.so.6(GLIBC_2.4)(64bit) libgcc_s.so.1()(64bit) libgcc_s.so.1(GCC_3.0)(64bit) libginac.so.4()(64bit) libm.so.6()(64bit) libm.so.6(GLIBC_2.2.5)(64bit) libpthread.so.0()(64bit) libpthread.so.0(GLIBC_2.2.5)(64bit) libstdc++.so.6()(64bit) libstdc++.so.6(CXXABI_1.3)(64bit) libstdc++.so.6(GLIBCXX_3.4)(64bit) libstdc++.so.6(GLIBCXX_3.4.15)(64bit) rtld(GNU_HASH)

%description
The QSS Solver is a modeling and simulation environment for continuous and hybrid systems.
Models are described using a subset of the Modelica language called MicroMoledica.
Simulations can be performed using one of the following integration methods:
* QSS methods (the entire family is supported)
* DASSL
* DOPRI

%files
/opt/qss-solver/COPYING
/opt/qss-solver/INSTALL
/opt/qss-solver/README.txt
/opt/qss-solver/version
/opt/qss-solver/bin/mmoc
/opt/qss-solver/bin/qss-solver
/opt/qss-solver/bin/translate-sbml
/opt/qss-solver/bin/qss-solver.ini
/opt/qss-solver/bin/exportvars.sh
/opt/qss-solver/bin/sbml.sh
/opt/qss-solver/bin/build.sh
/opt/qss-solver/bin/registervars.sh
/opt/qss-solver/bin/simulate.sh
/opt/qss-solver/bin/run.sh
/opt/qss-solver/bin/runtests.sh
/opt/qss-solver/bin/compile.sh
/opt/qss-solver/bin/gnuplot.sh
/opt/qss-solver/bin/mmoc.sh
/opt/qss-solver/bin/runqss.sh
/opt/qss-solver/doc/gui
/opt/qss-solver/doc/gui/html
/opt/qss-solver/doc/gui/latex
/opt/qss-solver/doc/engine
/opt/qss-solver/doc/engine/latex
/opt/qss-solver/doc/engine/html
/opt/qss-solver/doc/INSTALL
/opt/qss-solver/doc/ChangeLog
/opt/qss-solver/doc/COPYING
/opt/qss-solver/doc/README.txt
/opt/qss-solver/doc/mmoc
/opt/qss-solver/doc/mmoc/html
/opt/qss-solver/doc/mmoc/latex
/opt/qss-solver/doc/NEWS
/opt/qss-solver/doc/manual
/opt/qss-solver/doc/manual/manual.tex
/opt/qss-solver/doc/manual/images
/opt/qss-solver/doc/manual/images/arquitectura_codegen.odg
/opt/qss-solver/doc/manual/images/arquitectura_engine.odg
/opt/qss-solver/doc/manual/images/inverters_pdevs.eps
/opt/qss-solver/doc/manual/images/interleaved.pdf
/opt/qss-solver/doc/manual/images/ioquant2.pdf
/opt/qss-solver/doc/manual/images/gpx_buck.pdf
/opt/qss-solver/doc/manual/images/ioquant3.pdf
/opt/qss-solver/doc/manual/images/codegen.pdf
/opt/qss-solver/doc/manual/images/arq_gui.eps
/opt/qss-solver/doc/manual/images/qosc1.svg
/opt/qss-solver/doc/manual/images/gpx_airs.pdf
/opt/qss-solver/doc/manual/images/qosc2.svg
/opt/qss-solver/doc/manual/images/pres_plexim.tex
/opt/qss-solver/doc/manual/images/qosc3.svg
/opt/qss-solver/doc/manual/images/qosc4.svg
/opt/qss-solver/doc/manual/images/gpx_buck.eps
/opt/qss-solver/doc/manual/images/journals.bib
/opt/qss-solver/doc/manual/images/ioquant.pdf
/opt/qss-solver/doc/manual/images/codegen.pdf.2012_12_13_15_57_55.0.svg
/opt/qss-solver/doc/manual/images/buck_pdevs.pdf
/opt/qss-solver/doc/manual/images/arq_codegen.eps
/opt/qss-solver/doc/manual/images/arq_engine.eps
/opt/qss-solver/doc/manual/images/ioquant2.svg
/opt/qss-solver/doc/manual/images/interleaved.svg
/opt/qss-solver/doc/manual/images/ioquant3.svg
/opt/qss-solver/doc/manual/images/gpx_airs.eps
/opt/qss-solver/doc/manual/images/codegen.svg
/opt/qss-solver/doc/manual/images/empty-1.pdf
/opt/qss-solver/doc/manual/images/empty.pdf
/opt/qss-solver/doc/manual/images/airs_pdevs.pdf
/opt/qss-solver/doc/manual/images/gpx_inverters.pdf
/opt/qss-solver/doc/manual/images/buck_pdevs.eps
/opt/qss-solver/doc/manual/images/scheme.pdf
/opt/qss-solver/doc/manual/images/ioquant.svg
/opt/qss-solver/doc/manual/images/empty-1.png
/opt/qss-solver/doc/manual/images/interleaved_mod.jpg
/opt/qss-solver/doc/manual/images/empty.png
/opt/qss-solver/doc/manual/images/airs_pdevs.eps
/opt/qss-solver/doc/manual/images/arquitectura_gui.odg
/opt/qss-solver/doc/manual/images/gpx_inverters.eps
/opt/qss-solver/doc/manual/images/bball_mo.jpg
/opt/qss-solver/doc/manual/images/inverters_pdevs.pdf
/opt/qss-solver/doc/manual/images/pdevs_bball.jpg
/opt/qss-solver/doc/manual/images/qosc1.pdf
/opt/qss-solver/doc/manual/images/qosc2.pdf
/opt/qss-solver/doc/manual/images/qosc3.pdf
/opt/qss-solver/doc/manual/images/qosc4.pdf
/opt/qss-solver/doc/manual/images/scheme.svg
/opt/qss-solver/doc/sbml
/opt/qss-solver/doc/sbml/latex
/opt/qss-solver/doc/sbml/html
/opt/qss-solver/doc/specification
/opt/qss-solver/doc/specification/mmospec.pdf
/opt/qss-solver/doc/specification/mmospec.tex
/opt/qss-solver/models/lc_line
/opt/qss-solver/models/lc_line/lc_line.mo
/opt/qss-solver/models/lotka-volterra
/opt/qss-solver/models/lotka-volterra/lotka_volterra.mo
/opt/qss-solver/models/spikings
/opt/qss-solver/models/spikings/spikings.mo
/opt/qss-solver/models/converters
/opt/qss-solver/models/converters/cuk.mo
/opt/qss-solver/models/converters/buck.mo
/opt/qss-solver/models/converters/cuk2.mo
/opt/qss-solver/models/converters/boost.mo
/opt/qss-solver/models/converters/buckboost.mo
/opt/qss-solver/models/advection
/opt/qss-solver/models/advection/advection.mo
/opt/qss-solver/models/bball
/opt/qss-solver/models/bball/bball_downstairs.mo
/opt/qss-solver/models/rectifier
/opt/qss-solver/models/rectifier/rectifier.mo
/opt/qss-solver/models/airs
/opt/qss-solver/models/airs/aircont.mo
/opt/qss-solver/models/airs/airconds.mo
/opt/qss-solver/models/inverters
/opt/qss-solver/models/inverters/inverters.mo
/opt/qss-solver/models/interleaved
/opt/qss-solver/models/interleaved/buck_circuit.mo
/opt/qss-solver/models/interleaved/interleaved.mo
/opt/qss-solver/usr/Makefile
/opt/qss-solver/usr/include
/opt/qss-solver/usr/include/mmo_math.h
/opt/qss-solver/usr/include/mmo_file.h
/opt/qss-solver/usr/src
/opt/qss-solver/usr/src/mmo_math.c
/opt/qss-solver/usr/src/mmo_file.c
/opt/qss-solver/usr/libs
/opt/qss-solver/packages/math.mo
/opt/qss-solver/packages/file.mo
/opt/qss-solver/src/gui
/opt/qss-solver/src/gui/runform.cpp
/opt/qss-solver/src/gui/mmome.pro
/opt/qss-solver/src/gui/editor.h
/opt/qss-solver/src/gui/ui
/opt/qss-solver/src/gui/ui/mmomegui.ui
/opt/qss-solver/src/gui/ui/settings.ui
/opt/qss-solver/src/gui/ui/run.ui
/opt/qss-solver/src/gui/ui/modeleditor.ui
/opt/qss-solver/src/gui/moc
/opt/qss-solver/src/gui/utils.cpp
/opt/qss-solver/src/gui/settings.cpp
/opt/qss-solver/src/gui/modeleditor.cpp
/opt/qss-solver/src/gui/comboboxdelegate.h
/opt/qss-solver/src/gui/tags
/opt/qss-solver/src/gui/mmomegui.cpp
/opt/qss-solver/src/gui/modelinfo.h
/opt/qss-solver/src/gui/codeeditor.cpp
/opt/qss-solver/src/gui/treeitem.h
/opt/qss-solver/src/gui/images
/opt/qss-solver/src/gui/images/copy.png
/opt/qss-solver/src/gui/images/ImportFile.png
/opt/qss-solver/src/gui/images/paste.png
/opt/qss-solver/src/gui/images/prev.png
/opt/qss-solver/src/gui/images/next.png
/opt/qss-solver/src/gui/images/find.png
/opt/qss-solver/src/gui/images/log.png
/opt/qss-solver/src/gui/images/saveas.png
/opt/qss-solver/src/gui/images/editfile.png
/opt/qss-solver/src/gui/images/cancel.png
/opt/qss-solver/src/gui/images/newfolder.png
/opt/qss-solver/src/gui/images/folder.svg
/opt/qss-solver/src/gui/images/debug.png
/opt/qss-solver/src/gui/images/clear.png
/opt/qss-solver/src/gui/images/save_all.png
/opt/qss-solver/src/gui/images/gnuplot.png
/opt/qss-solver/src/gui/images/compile.png
/opt/qss-solver/src/gui/images/integrator.svg
/opt/qss-solver/src/gui/images/newFile.png
/opt/qss-solver/src/gui/images/cut.png
/opt/qss-solver/src/gui/images/document_save.png
/opt/qss-solver/src/gui/images/run_copy.png
/opt/qss-solver/src/gui/images/editfile.svg
/opt/qss-solver/src/gui/images/newfolder.svg
/opt/qss-solver/src/gui/images/settings.png
/opt/qss-solver/src/gui/images/multiplier.svg
/opt/qss-solver/src/gui/images/open.png
/opt/qss-solver/src/gui/images/delete.png
/opt/qss-solver/src/gui/images/gnuplot.svg
/opt/qss-solver/src/gui/images/newFile.svg
/opt/qss-solver/src/gui/images/run.png
/opt/qss-solver/src/gui/main.cpp
/opt/qss-solver/src/gui/treemodel.h
/opt/qss-solver/src/gui/mmohighlight.h
/opt/qss-solver/src/gui/editor.cpp
/opt/qss-solver/src/gui/obj
/opt/qss-solver/src/gui/runform.h
/opt/qss-solver/src/gui/comboboxdelegate.cpp
/opt/qss-solver/src/gui/settings.h
/opt/qss-solver/src/gui/utils.h
/opt/qss-solver/src/gui/QSSSolverGUI.doxyfile
/opt/qss-solver/src/gui/modelinfo.cpp
/opt/qss-solver/src/gui/modeleditor.h
/opt/qss-solver/src/gui/mmome.qrc
/opt/qss-solver/src/gui/treeitem.cpp
/opt/qss-solver/src/gui/mmohighlight.cpp
/opt/qss-solver/src/gui/treemodel.cpp
/opt/qss-solver/src/gui/mmomegui.h
/opt/qss-solver/src/gui/codeeditor.h
/opt/qss-solver/src/engine
/opt/qss-solver/src/engine/dassl
/opt/qss-solver/src/engine/dassl/ddaskr.f
/opt/qss-solver/src/engine/dassl/dassl_integrator.c
/opt/qss-solver/src/engine/dassl/daux.f
/opt/qss-solver/src/engine/dassl/dlinpk.f
/opt/qss-solver/src/engine/dassl/dassl_integrator.h
/opt/qss-solver/src/engine/qss
/opt/qss-solver/src/engine/qss/qss3.c
/opt/qss-solver/src/engine/qss/qss4.c
/opt/qss-solver/src/engine/qss/liqss.c
/opt/qss-solver/src/engine/qss/qss2.h
/opt/qss-solver/src/engine/qss/qss3.h
/opt/qss-solver/src/engine/qss/qss_memory.c
/opt/qss-solver/src/engine/qss/qss_data.c
/opt/qss-solver/src/engine/qss/qss4.h
/opt/qss-solver/src/engine/qss/qss_linear.c
/opt/qss-solver/src/engine/qss/liqss.h
/opt/qss-solver/src/engine/qss/qss_lp.c
/opt/qss-solver/src/engine/qss/qss_memory.h
/opt/qss-solver/src/engine/qss/qss_scheduler.c
/opt/qss-solver/src/engine/qss/qss_data.h
/opt/qss-solver/src/engine/qss/qss_linear.h
/opt/qss-solver/src/engine/qss/qss_file.c
/opt/qss-solver/src/engine/qss/qss.c
/opt/qss-solver/src/engine/qss/qss_lp.h
/opt/qss-solver/src/engine/qss/qss_quantizer.c
/opt/qss-solver/src/engine/qss/qss_scheduler.h
/opt/qss-solver/src/engine/qss/qss_file.h
/opt/qss-solver/src/engine/qss/qss.h
/opt/qss-solver/src/engine/qss/qss_quantizer.h
/opt/qss-solver/src/engine/qss/liqss2.c
/opt/qss-solver/src/engine/qss/liqss3.c
/opt/qss-solver/src/engine/qss/liqss2.h
/opt/qss-solver/src/engine/qss/qss_parallel.c
/opt/qss-solver/src/engine/qss/liqss3.h
/opt/qss-solver/src/engine/qss/qss_frw.c
/opt/qss-solver/src/engine/qss/qss_output.c
/opt/qss-solver/src/engine/qss/qss_parallel.h
/opt/qss-solver/src/engine/qss/qss_frw.h
/opt/qss-solver/src/engine/qss/qss_model.h
/opt/qss-solver/src/engine/qss/qss_output.h
/opt/qss-solver/src/engine/qss/qss_biorica.c
/opt/qss-solver/src/engine/qss/qss_partition.c
/opt/qss-solver/src/engine/qss/qss_step.c
/opt/qss-solver/src/engine/qss/qss_biorica.h
/opt/qss-solver/src/engine/qss/qss_integrator.c
/opt/qss-solver/src/engine/qss/qss_partition.h
/opt/qss-solver/src/engine/qss/qss_step.h
/opt/qss-solver/src/engine/qss/qss_log.c
/opt/qss-solver/src/engine/qss/qss_integrator.h
/opt/qss-solver/src/engine/qss/cqss.c
/opt/qss-solver/src/engine/qss/qss_binary.c
/opt/qss-solver/src/engine/qss/qss_binary_random.c
/opt/qss-solver/src/engine/qss/qss_sampled.c
/opt/qss-solver/src/engine/qss/qss_log.h
/opt/qss-solver/src/engine/qss/cqss.h
/opt/qss-solver/src/engine/qss/qss_binary.h
/opt/qss-solver/src/engine/qss/qss_binary_random.h
/opt/qss-solver/src/engine/qss/qss_sampled.h
/opt/qss-solver/src/engine/qss/qss2.c
/opt/qss-solver/src/engine/common
/opt/qss-solver/src/engine/common/data.h
/opt/qss-solver/src/engine/common/integrator.c
/opt/qss-solver/src/engine/common/classic_data.h
/opt/qss-solver/src/engine/common/classic_integrator.c
/opt/qss-solver/src/engine/common/random.c
/opt/qss-solver/src/engine/common/settings.c
/opt/qss-solver/src/engine/common/utils.c
/opt/qss-solver/src/engine/common/integrator.h
/opt/qss-solver/src/engine/common/classic_integrator.h
/opt/qss-solver/src/engine/common/random.h
/opt/qss-solver/src/engine/common/settings.h
/opt/qss-solver/src/engine/common/utils.h
/opt/qss-solver/src/engine/common/classic_model.h
/opt/qss-solver/src/engine/common/data.c
/opt/qss-solver/src/engine/common/classic_data.c
/opt/qss-solver/src/engine/tags
/opt/qss-solver/src/engine/dopri5
/opt/qss-solver/src/engine/dopri5/dopri_integrator.h
/opt/qss-solver/src/engine/dopri5/dopri5.c
/opt/qss-solver/src/engine/dopri5/dopri5.h
/opt/qss-solver/src/engine/dopri5/dopri_integrator.c
/opt/qss-solver/src/engine/QSSSolver.doxyfile
/opt/qss-solver/src/mmo
/opt/qss-solver/src/mmo/api
/opt/qss-solver/src/mmo/ir
/opt/qss-solver/src/mmo/ir/mmo_model_checker.cpp
/opt/qss-solver/src/mmo/ir/expression.cpp
/opt/qss-solver/src/mmo/ir/mmo_model_checker.h
/opt/qss-solver/src/mmo/ir/mmo_flatten_array.cpp
/opt/qss-solver/src/mmo/ir/expression.h
/opt/qss-solver/src/mmo/ir/statement.cpp
/opt/qss-solver/src/mmo/ir/class.cpp
/opt/qss-solver/src/mmo/ir/mmo_flatten_array.h
/opt/qss-solver/src/mmo/ir/mmo_settings.cpp
/opt/qss-solver/src/mmo/ir/stored_definition.cpp
/opt/qss-solver/src/mmo/ir/statement.h
/opt/qss-solver/src/mmo/ir/annotation.cpp
/opt/qss-solver/src/mmo/ir/class.h
/opt/qss-solver/src/mmo/ir/mmo_settings.h
/opt/qss-solver/src/mmo/ir/stored_definition.h
/opt/qss-solver/src/mmo/ir/Makefile.include
/opt/qss-solver/src/mmo/ir/annotation.h
/opt/qss-solver/src/mmo/ir/mmo_types.h
/opt/qss-solver/src/mmo/ir/event.cpp
/opt/qss-solver/src/mmo/ir/mmo_ir.cpp
/opt/qss-solver/src/mmo/ir/mmo_util.cpp
/opt/qss-solver/src/mmo/ir/equation.cpp
/opt/qss-solver/src/mmo/ir/event.h
/opt/qss-solver/src/mmo/ir/mmo_ir.h
/opt/qss-solver/src/mmo/ir/mmo_base.h
/opt/qss-solver/src/mmo/ir/mmo_util.h
/opt/qss-solver/src/mmo/ir/equation.h
/opt/qss-solver/src/mmo/parser
/opt/qss-solver/src/mmo/parser/config.h
/opt/qss-solver/src/mmo/parser/parse.cpp
/opt/qss-solver/src/mmo/parser/mocc_parser.output
/opt/qss-solver/src/mmo/parser/parse.h
/opt/qss-solver/src/mmo/parser/mocc.lex
/opt/qss-solver/src/mmo/parser/mocc.y
/opt/qss-solver/src/mmo/Makefile
/opt/qss-solver/src/mmo/util
/opt/qss-solver/src/mmo/util/debug.h
/opt/qss-solver/src/mmo/util/error.h
/opt/qss-solver/src/mmo/util/ginac_interface.cpp
/opt/qss-solver/src/mmo/util/derivate.cpp
/opt/qss-solver/src/mmo/util/compile_flags.cpp
/opt/qss-solver/src/mmo/util/ginac_interface.h
/opt/qss-solver/src/mmo/util/util_types.h
/opt/qss-solver/src/mmo/util/index.cpp
/opt/qss-solver/src/mmo/util/derivate.h
/opt/qss-solver/src/mmo/util/compile_flags.h
/opt/qss-solver/src/mmo/util/symbol_table.cpp
/opt/qss-solver/src/mmo/util/index.h
/opt/qss-solver/src/mmo/util/dependences.cpp
/opt/qss-solver/src/mmo/util/util.cpp
/opt/qss-solver/src/mmo/util/type_check.cpp
/opt/qss-solver/src/mmo/util/symbol_table.h
/opt/qss-solver/src/mmo/util/type.cpp
/opt/qss-solver/src/mmo/util/util.h
/opt/qss-solver/src/mmo/util/dependences.h
/opt/qss-solver/src/mmo/util/type_check.h
/opt/qss-solver/src/mmo/util/ast_util.cpp
/opt/qss-solver/src/mmo/util/debug.cpp
/opt/qss-solver/src/mmo/util/type.h
/opt/qss-solver/src/mmo/util/error.cpp
/opt/qss-solver/src/mmo/util/ast_util.h
/opt/qss-solver/src/mmo/util/macros.h
/opt/qss-solver/src/mmo/include
/opt/qss-solver/src/mmo/include/patoh.h
/opt/qss-solver/src/mmo/MMOCompiler.doxyfile
/opt/qss-solver/src/mmo/main.cpp
/opt/qss-solver/src/mmo/lib
/opt/qss-solver/src/mmo/lib/libpatoh.a
/opt/qss-solver/src/mmo/generator
/opt/qss-solver/src/mmo/generator/scripts.h
/opt/qss-solver/src/mmo/generator/Makefile.include
/opt/qss-solver/src/mmo/generator/generator_types.h
/opt/qss-solver/src/mmo/generator/solver.h
/opt/qss-solver/src/mmo/generator/generator.cpp
/opt/qss-solver/src/mmo/generator/generator_utils.cpp
/opt/qss-solver/src/mmo/generator/scripts.cpp
/opt/qss-solver/src/mmo/generator/solver.cpp
/opt/qss-solver/src/mmo/generator/generator.h
/opt/qss-solver/src/mmo/generator/generator_utils.h
/opt/qss-solver/src/mmo/ast
/opt/qss-solver/src/mmo/ast/element.cpp
/opt/qss-solver/src/mmo/ast/equation.h
/opt/qss-solver/src/mmo/ast/ast_node.cpp
/opt/qss-solver/src/mmo/ast/ast_builder.cpp
/opt/qss-solver/src/mmo/ast/imports.cpp
/opt/qss-solver/src/mmo/ast/element.h
/opt/qss-solver/src/mmo/ast/expression.cpp
/opt/qss-solver/src/mmo/ast/ast_printer.h
/opt/qss-solver/src/mmo/ast/ast_node.h
/opt/qss-solver/src/mmo/ast/ast_builder.h
/opt/qss-solver/src/mmo/ast/imports.h
/opt/qss-solver/src/mmo/ast/composition.cpp
/opt/qss-solver/src/mmo/ast/expression.h
/opt/qss-solver/src/mmo/ast/statement.cpp
/opt/qss-solver/src/mmo/ast/class.cpp
/opt/qss-solver/src/mmo/ast/modification.cpp
/opt/qss-solver/src/mmo/ast/composition.h
/opt/qss-solver/src/mmo/ast/stored_definition.cpp
/opt/qss-solver/src/mmo/ast/statement.h
/opt/qss-solver/src/mmo/ast/class.h
/opt/qss-solver/src/mmo/ast/modification.h
/opt/qss-solver/src/mmo/ast/stored_definition.h
/opt/qss-solver/src/mmo/ast/ast_types.h
/opt/qss-solver/src/mmo/ast/equation.cpp
/opt/qss-solver/src/libs
/opt/qss-solver/src/libs/classic.makefile
/opt/qss-solver/src/libs/parallel.makefile
/opt/qss-solver/src/libs/serial.makefile
/opt/qss-solver/src/sbml
/opt/qss-solver/src/sbml/mmo_math.h
/opt/qss-solver/src/sbml/mmo_model.cpp
/opt/qss-solver/src/sbml/mmo_visitor.h
/opt/qss-solver/src/sbml/mmo_utils.h
/opt/qss-solver/src/sbml/tags
/opt/qss-solver/src/sbml/mmo_decl.cpp
/opt/qss-solver/src/sbml/mmo_assignment.cpp
/opt/qss-solver/src/sbml/mmo_section.h
/opt/qss-solver/src/sbml/mmo_writer.cpp
/opt/qss-solver/src/sbml/mmo_convert.cpp
/opt/qss-solver/src/sbml/mmo_event.cpp
/opt/qss-solver/src/sbml/Makefile
/opt/qss-solver/src/sbml/mmo_equation.cpp
/opt/qss-solver/src/sbml/mmo_function.cpp
/opt/qss-solver/src/sbml/mmo_zerocrossing.cpp
/opt/qss-solver/src/sbml/mmo_math.cpp
/opt/qss-solver/src/sbml/mmo_utils.cpp
/opt/qss-solver/src/sbml/biorica_writer.h
/opt/qss-solver/src/sbml/mmo_exp.h
/opt/qss-solver/src/sbml/mmo_section.cpp
/opt/qss-solver/src/sbml/mmo_model.h
/opt/qss-solver/src/sbml/convert.cpp
/opt/qss-solver/src/sbml/mmo_decl.h
/opt/qss-solver/src/sbml/mmo_assignment.h
/opt/qss-solver/src/sbml/mmo_writer.h
/opt/qss-solver/src/sbml/mmo_convert.h
/opt/qss-solver/src/sbml/sbml.Doxyfile
/opt/qss-solver/src/sbml/mmo_event.h
/opt/qss-solver/src/sbml/mmo_function.h
/opt/qss-solver/src/sbml/mmo_equation.h
/opt/qss-solver/src/sbml/mmo_zerocrossing.h
/opt/qss-solver/src/sbml/biorica_writer.cpp
/opt/qss-solver/src/Makefile
/opt/qss-solver/src/libs/libclci.a
/opt/qss-solver/src/libs/libclcid.a
/opt/qss-solver/src/libs/libqssc.a
/opt/qss-solver/src/libs/libqsscd.a
/opt/qss-solver/src/libs/libqssco.a
/opt/qss-solver/src/libs/libqsscod.a
/opt/qss-solver/src/libs/libqssh.a
/opt/qss-solver/src/libs/libqsshd.a
/opt/qss-solver/src/libs/libqssho.a
/opt/qss-solver/src/libs/libqsshod.a
/opt/qss-solver/src/libs/libtimestep.a
/opt/qss-solver/src/libs/libtimestepd.a
/opt/qss-solver/src/libs/libsbml.so.5


