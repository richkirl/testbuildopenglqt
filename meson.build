project('trainingkeyboard', 'cpp', default_options : ['cpp_std=c++17'], version : '0.1')
qt5 = import('qt5')
qt5_dep = dependency('qt5', modules: ['Core', 'Gui', 'Widgets', 'OpenGL'])
gl_dep = dependency('GL')
moc_files = qt5.preprocess(moc_headers : 'trkbd.hpp',
                                       dependencies : [qt5_dep, gl_dep])
executable('trainingkeyboard','main.cpp', 'trkbd.cpp', moc_files, dependencies : [qt5_dep, gl_dep])
