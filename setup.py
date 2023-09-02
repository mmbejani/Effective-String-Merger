from pybind11.setup_helpers import Pybind11Extension, build_ext
from setuptools import setup

__version__ = "0.0.1"

ext_modules = [
    Pybind11Extension(
        "za_string_merger",
        ["native/src/utils.cc"],
        define_macros=[("VERSION_INFO", __version__)],
        include_dirs=["native/header/utils.h"],
    )
]

setup(
    name="za-string-merger",
    version=__version__,
    author="Mohammad Mahdi Bejani",
    author_email="mbejani@aut.ac.ir",
    url="https://github.com/mmbejani/Effective-String-Merger",
    description="A simple pybind library for string merging",
    long_description="",
    ext_modules=ext_modules,
    cmdclass={"build_ext": build_ext},
    zip_safe=False,
    python_requires=">=3.7",
)
