function(add_glfwcxx_target)
    set(options)
    set(oneValueArgs NAME)
    set(multiValueArgs SOURCES STUB_SOURCES)
    cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    set(CURRENT_TARGET ${ARG_NAME})
    set(CURRENT_STUB_TARGET ${CURRENT_TARGET}-stub)

    add_library(${CURRENT_TARGET} STATIC ${ARG_SOURCES})
    target_include_directories(
        ${CURRENT_TARGET} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/${ARG_NAME}>)
    target_link_libraries(${CURRENT_TARGET} PRIVATE $<BUILD_INTERFACE:glfw::glfw>)

    add_library(${CURRENT_STUB_TARGET} STATIC ${ARG_SOURCES} ${ARG_STUB_SOURCES})
    target_include_directories(
        ${CURRENT_STUB_TARGET}
        PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/${ARG_NAME}>
               $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/stub>)
    target_link_libraries(${CURRENT_STUB_TARGET} PRIVATE $<BUILD_INTERFACE:glfwstub>)
    target_compile_definitions(${CURRENT_STUB_TARGET} PUBLIC GLFWCXX_STUB)
endfunction()

function(install_glfwcxx_target)
    set(options)
    set(oneValueArgs NAME)
    set(multiValueArgs)
    cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    set(CURRENT_TARGET ${ARG_NAME})
    set(CURRENT_STUB_TARGET ${CURRENT_TARGET}-stub)

    install(
        TARGETS ${CURRENT_TARGET}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        INCLUDES
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
    install(
        TARGETS ${CURRENT_STUB_TARGET}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        INCLUDES
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
    install(DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/include/${ARG_NAME}/glfwcxx
            DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
    install(DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/include/stub/glfwcxx
            DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
endfunction()
