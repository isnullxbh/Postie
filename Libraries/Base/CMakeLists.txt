add_library(Postie.Base)

set_target_properties(Postie.Base
    PROPERTIES
        OUTPUT_NAME "Postie.Base"
        PREFIX      "")

target_compile_features(Postie.Base
    PUBLIC
        cxx_std_20)

target_sources(Postie.Base
    PUBLIC
        FILE_SET postie_base TYPE CXX_MODULES
            FILES
                FixedString.cppm
                TypeList.cppm)

add_library(Postie::Base ALIAS Postie.Base)
