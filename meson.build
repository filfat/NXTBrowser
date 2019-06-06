project('NXTBrowser', ['c', 'cpp'],
    version: '1.0.0',
    license: 'MIT',
    default_options: [
        'warning_level=3',
        'b_pch=false',

        'c_std=c99',
        'cpp_std=c++11'
    ]
)

security_args = [
    '-fexceptions',
    '-Wfatal-errors',
    '-Werror'
]
cpp_args = [
    '-Wall',
    '-Wno-conversion-null',
    '-Wno-int-to-pointer-cast',
    '-Wno-unused-result',
    '-Wno-unused-variable',
    '-Wno-unused-value'
]
link_args = []
dep = [
    dependency('tidy'),
    dependency('curl'),
    dependency('sdl2'),
    dependency('sdl2_image'),
    dependency('sdl2_ttf')
]

if get_option('buildtype').startswith('debug')
    cpp_args += ['-D__DEBUG__']
else
    security_args += [
        '-D_FORTIFY_SOURCE=2',
        '-Wl,dynamicbase',
        '-Wsign-conversion',
#        '-mmitigate-rop',
        '-fstack-protector-strong',
        '-fcf-protection',
    ]
endif

if build_machine.system() == 'darwin'
    link_args += [
        'c_std=c11',
        'cpp_std=c++17'
    ]

    cpp_args += ['-D__DARWIN__']
    
    dep_libui = dependency('libui', required: false)
    if not dep_libui.found()
        proj_libui = subproject('libui')
        dep_libui = proj_libui.get_variable('libui_deps')
    endif
    dep += [dep_libui]
elif build_machine.system() == 'linux'
    cpp_args += ['-D__LINUX__']
elif build_machine.system() == 'windows'
    cpp_args += ['-D__WIN32__']
endif

if build_machine.system() == 'darwin'
    link_args += ['-lstdc++fs']
elif build_machine.system() == 'linux'
    # TODO
elif build_machine.system() == 'windows'
    # TODO
endif

includes = [include_directories('src/include')]
src = [
    'src/source/main.cpp',

    'src/source/dom/dom.cpp',

    'src/source/gui/gui.cpp',
    'src/source/gui/ui/aboutWindow.cpp',
    'src/source/gui/ui/mainWindow.cpp',

    'src/source/html/parser.cpp',
    'src/source/html/validator.cpp',

    'src/source/input/input.cpp',

    'src/source/libs/tinyxml2/tinyxml2.cpp',

    'src/source/net/net.cpp',

    'src/source/stack/stack.cpp',
]
cpp_args += security_args
executable('NXTBrowser', src, dependencies: dep, cpp_args: cpp_args, link_args: link_args, include_directories: includes)
