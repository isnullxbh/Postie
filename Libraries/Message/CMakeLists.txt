add_library(Postie.Message)

set_target_properties(Postie.Message
    PROPERTIES
        OUTPUT_NAME "Postie.Message"
        PREFIX      "")

target_compile_features(Postie.Message
    PUBLIC
        cxx_std_20)

target_sources(Postie.Message
    PUBLIC
        FILE_SET postie_message TYPE CXX_MODULES
            FILES
                Models/Field.cppm
                Models/FieldMessage.cppm
                Models/FieldSet.cppm
                Models/Message.cppm
                Models/MessageSet.cppm
                Message.cppm
                MessageType.cppm)

target_link_libraries(Postie.Message
    PUBLIC
        Postie::Base)

add_library(Postie::Message ALIAS Postie.Message)
