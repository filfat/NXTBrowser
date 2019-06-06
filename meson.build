project('NXTBrowser', 'cpp',
  version : '1.0.0',
  license : 'MIT',
  default_options : ['c_std=c17', 'cpp_std=c++17'])

security_args = [
  '-fexceptions',
  '-Werror'
]
cpp_args = [
  '-Wall',
  '-Wno-conversion-null',
  '-Wno-int-to-pointer-cast',
  '-Wno-unused-result'
]
link_args = []
dep = []

if get_option('buildtype').startswith('debug')
  cpp_args += ['-D__DEBUG__']
else
  security_args += [
    '-D_FORTIFY_SOURCE=2',
    '-Wl,dynamicbase',
    '-Wsign-conversion',
    '-mmitigate-rop',
    '-fstack-protector-strong',
    '-fcf-protection',
  ]
endif

if build_machine.system() == 'darwin'
  cpp_args += ['-D__DARWIN__']
elif build_machine.system() == 'linux'
  cpp_args += ['-D__LINUX__']
elif build_machine.system() == 'windows'
  cpp_args += ['-D__WIN32__']
endif

if build_machine.system() == 'darwin'
  # TODO: Metal for darwin?
  dep_glew = dependency('glew')
  dep_glfw3 = dependency('glfw3')

  cpp_args += ['-D__USE_OPENGL__']
  link_args += ['-lstdc++fs']
  dep += [dep_glew, dep_glfw3, dep_usb, dep_lua]
elif build_machine.system() == 'linux'
  dep_glew = dependency('glew')
  dep_glfw3 = dependency('glfw3')

  cpp_args += ['-D__USE_OPENGL__']
  link_args += ['-lstdc++fs']
  dep += [dep_glew, dep_glfw3, dep_usb, dep_lua]
elif build_machine.system() == 'windows'
  # TODO
endif

source_files_finder = run_command('source_files.sh')
main_src = source_files_finder.stdout().strip().split('\n')
cpp_args += security_args
executable('openmelee', main_src, dependencies: dep, cpp_args: cpp_args, link_args: link_args)
