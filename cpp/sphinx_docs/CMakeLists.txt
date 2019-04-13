cmake_minimum_required (VERSION 2.6)
project (Sphinx_Docs_Demo)
 
# to build docs
macro(add_sphinx_target TARGET_NAME BUILDER COMMENT_STR)
    add_custom_target(${TARGET_NAME}
    COMMAND sphinx-build -b ${BUILDER} . sphinx_build/${BUILDER}
        WORKING_DIRECTORY docs
        DEPENDS doxygen
        COMMENT ${COMMENT_STR}
    )

endmacro(add_sphinx_target)

add_custom_target(doxygen
    COMMAND doxygen docs/doxygen.conf
    COMMENT "Build doxygen xml files used by sphinx/breathe."
)

add_sphinx_target(docs-html
    html
    "Build html documentation"
)

