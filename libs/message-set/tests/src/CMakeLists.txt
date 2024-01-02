find_package(GTest CONFIG REQUIRED)

add_executable(Postie.MessageSet.Tests)

target_include_directories(Postie.MessageSet.Tests
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/../include
        ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(Postie.MessageSet.Tests
    PRIVATE
        main.cpp
        # Models
        Postie/Models/Field.Test.cpp
        Postie/Models/FieldSet.Test.cpp
        Postie/Models/MapMessage.Test.cpp
        Postie/Models/Message.Test.cpp
        Postie/Models/MessageSet.Test.cpp
        Postie/Models/ObjectField.Test.cpp)

target_link_libraries(Postie.MessageSet.Tests
    GTest::gtest
    Postie::MessageSet)
