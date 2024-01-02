find_package(ext CONFIG REQUIRED)

add_library(Postie.MessageSet INTERFACE)
add_library(Postie::MessageSet ALIAS Postie.MessageSet)

set_target_properties(Postie.MessageSet
    PROPERTIES
        OUTPUT_NAME "Postie.MessageSet"
        PREFIX      "")

target_include_directories(Postie.MessageSet
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../include>
        $<INSTALL_INTERFACE:include>)

target_sources(Postie.MessageSet
    INTERFACE
        FILE_SET HEADERS
            BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/../include
            FILES
                ${CMAKE_CURRENT_SOURCE_DIR}/../include/Postie/Models/Detail/AreUniqueFields.hpp
                ${CMAKE_CURRENT_SOURCE_DIR}/../include/Postie/Models/Detail/AreUniqueMessages.hpp
                ${CMAKE_CURRENT_SOURCE_DIR}/../include/Postie/Models/Field.hpp
                ${CMAKE_CURRENT_SOURCE_DIR}/../include/Postie/Models/FieldSet.hpp
                ${CMAKE_CURRENT_SOURCE_DIR}/../include/Postie/Models/MapMessage.hpp
                ${CMAKE_CURRENT_SOURCE_DIR}/../include/Postie/Models/Message.hpp
                ${CMAKE_CURRENT_SOURCE_DIR}/../include/Postie/Models/MessageSet.hpp
                ${CMAKE_CURRENT_SOURCE_DIR}/../include/Postie/Models/Models.hpp
                ${CMAKE_CURRENT_SOURCE_DIR}/../include/Postie/Models/ObjectField.hpp)

target_link_libraries(Postie.MessageSet
    INTERFACE
        ext)
