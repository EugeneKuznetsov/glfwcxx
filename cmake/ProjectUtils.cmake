function(add_glfwcxx_target)
    set(options)
    set(oneValueArgs GLFWCXX_TARGET_NAME)
    set(multiValueArgs TARGET_SOURCES PRIVATE_DEPENDENCY_TARGETS)
    cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    set(GLFWCXX_TARGET ${ARG_GLFWCXX_TARGET_NAME})
    set(GLFWCXX_OBJECT_TARGET ${GLFWCXX_TARGET}-object)

    add_library(${GLFWCXX_OBJECT_TARGET} OBJECT ${ARG_TARGET_SOURCES})
    target_sources(${GLFWCXX_OBJECT_TARGET} INTERFACE ${ARG_TARGET_SOURCES})
    target_include_directories(
        ${GLFWCXX_OBJECT_TARGET}
        PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/${GLFWCXX_TARGET}>)
    foreach(DEPENDENCY_TARGET IN LISTS ARG_PRIVATE_DEPENDENCY_TARGETS)
        if(NOT TARGET ${DEPENDENCY_TARGET})
            message(FATAL_ERROR "${DEPENDENCY_TARGET} is not a real target")
        endif()
        get_target_property(DEPENDENCY_HEADERS ${DEPENDENCY_TARGET} INTERFACE_INCLUDE_DIRECTORIES)
        target_include_directories(${GLFWCXX_OBJECT_TARGET}
                                   PRIVATE $<BUILD_INTERFACE:${DEPENDENCY_HEADERS}>)
    endforeach()

    add_library(${GLFWCXX_TARGET} STATIC $<TARGET_OBJECTS:${GLFWCXX_OBJECT_TARGET}>)
    target_include_directories(
        ${GLFWCXX_TARGET}
        INTERFACE $<TARGET_PROPERTY:${GLFWCXX_OBJECT_TARGET},INTERFACE_INCLUDE_DIRECTORIES>)
    foreach(DEPENDENCY_TARGET IN LISTS ARG_PRIVATE_DEPENDENCY_TARGETS)
        target_link_libraries(${GLFWCXX_TARGET} PRIVATE $<BUILD_INTERFACE:${DEPENDENCY_TARGET}>)
    endforeach()

    add_library(glfwcxx::${GLFWCXX_TARGET} ALIAS ${GLFWCXX_TARGET})
endfunction()

function(add_glfwcxx_stub_target)
    set(options)
    set(oneValueArgs GLFWCXX_TARGET_NAME)
    set(multiValueArgs TARGET_SOURCES PRIVATE_DEPENDENCY_TARGETS)
    cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    set(GLFWCXX_TARGET ${ARG_GLFWCXX_TARGET_NAME})
    set(GLFWCXX_OBJECT_TARGET ${GLFWCXX_TARGET}-object)
    set(GLFWCXX_STUB_TARGET ${GLFWCXX_TARGET}-stub)

    add_library(${GLFWCXX_STUB_TARGET} STATIC
                ${ARG_TARGET_SOURCES} $<TARGET_PROPERTY:${GLFWCXX_OBJECT_TARGET},INTERFACE_SOURCES>)
    target_include_directories(
        ${GLFWCXX_STUB_TARGET}
        PUBLIC $<TARGET_PROPERTY:${GLFWCXX_OBJECT_TARGET},INTERFACE_INCLUDE_DIRECTORIES>
               $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/stub>)
    foreach(DEPENDENCY_TARGET IN LISTS ARG_PRIVATE_DEPENDENCY_TARGETS)
        target_link_libraries(${GLFWCXX_STUB_TARGET}
                              PRIVATE $<BUILD_INTERFACE:${DEPENDENCY_TARGET}>)
    endforeach()

    add_library(glfwcxx::${GLFWCXX_STUB_TARGET} ALIAS ${GLFWCXX_STUB_TARGET})
endfunction()

function(install_glfwcxx_target)
    set(options)
    set(oneValueArgs GLFWCXX_TARGET_NAME)
    set(multiValueArgs)
    cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    set(GLFWCXX_TARGET ${ARG_GLFWCXX_TARGET_NAME})
    install(
        TARGETS ${GLFWCXX_TARGET}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        INCLUDES
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
    install(DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/include/${GLFWCXX_TARGET}/glfwcxx
            DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
endfunction()

function(install_glfwcxx_stub_target)
    set(options)
    set(oneValueArgs GLFWCXX_TARGET_NAME)
    set(multiValueArgs)
    cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    set(GLFWCXX_STUB_TARGET ${ARG_GLFWCXX_TARGET_NAME}-stub)
    install(
        TARGETS ${GLFWCXX_STUB_TARGET}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        INCLUDES
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
    install(DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/include/stub/glfwcxx
            DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
endfunction()
