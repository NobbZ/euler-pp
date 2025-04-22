project('euler++', 'cpp',
  default_options: ['cpp_std=c++20', 'buildtype=debugoptimized', 'warning_level=everything', 'werror=true'],
)

catch2_dep = dependency('catch2-with-main', required: false)

subdir('include')

subdir('doc')
subdir('src')
subdir('tests')

euler_lib = library('euler_lib', euler_source_files,
  include_directories: includes,
  link_args: ['-lm'],
)

executable('euler', 'src/main.cpp',
  include_directories: includes,
  link_with: euler_lib,
  install: false,
) 

test_exe = executable('euler_tests', test_sources,
  include_directories: includes,
  dependencies: [catch2_dep],
  link_with: euler_lib,
)

test('euler tests', test_exe)
