project('euler++', 'cpp',
  default_options: ['cpp_std=c++20', 'buildtype=debugoptimized'],
)

subdir('include')
subdir('src')

executable('euler', euler_source_files,
  include_directories: includes,
  link_args: ['-lm'],
  install: false,
) 
