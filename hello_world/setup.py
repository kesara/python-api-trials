from distutils.core import setup, Extension

module = Extension('helloworld', sources=['helloworldmodule.c'])

setup(
    name='HelloWorld',
    version='1.0',
    description='Demo package.',
    ext_modules=[module])
