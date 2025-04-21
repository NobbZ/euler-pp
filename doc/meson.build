cdata = configuration_data()
cdata.set('TOP_SRCDIR', meson.project_source_root())
cdata.set('TOP_BUILDDIR', meson.project_build_root())
cdata.set('VERSION', meson.project_version())

doxygen = find_program('doxygen')

doxyfile = configure_file(
  input: 'Doxyfile.in',
  output: 'Doxyfile',
  configuration: cdata,
  install: false,
)

custom_target('docs',
  input: doxyfile,
  output: 'html',
  command: [doxygen, doxyfile],
  install: false,
)
