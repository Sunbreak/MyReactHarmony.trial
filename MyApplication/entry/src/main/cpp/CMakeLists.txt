project(rnapp)
cmake_minimum_required(VERSION 3.4.1)
set(CMAKE_SKIP_BUILD_RPATH TRUE)
set(OH_MODULE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../../../oh_modules")
set(RNOH_APP_DIR "${CMAKE_CURRENT_SOURCE_DIR}")

set(RNOH_CPP_DIR "${OH_MODULE_DIR}/@rnoh/react-native-openharmony/src/main/cpp")
set(CMAKE_ASM_FLAGS "-Wno-error=unused-command-line-argument -Qunused-arguments")
set(CMAKE_CXX_FLAGS "-fstack-protector-strong -Wl,-z,relro,-z,now,-z,noexecstack -s -fPIE -pie")
add_compile_definitions(WITH_HITRACE_SYSTRACE)
set(WITH_HITRACE_SYSTRACE 1) # for other CMakeLists.txt files to use

add_subdirectory("${RNOH_CPP_DIR}" ./rn)

# RNOH_BEGIN: add_package_subdirectories
add_subdirectory("${OH_MODULE_DIR}/rnoh-linear-gradient/src/main/cpp" ./linear-gradient)
add_subdirectory("${OH_MODULE_DIR}/rnoh-webview/src/main/cpp" ./webview)
add_subdirectory("${OH_MODULE_DIR}/rnoh-safe-area/src/main/cpp" ./safe-area)
add_subdirectory("${OH_MODULE_DIR}/rnoh-async-storage/src/main/cpp" ./async-storage)
add_subdirectory("${OH_MODULE_DIR}/rnoh-netinfo/src/main/cpp" ./netinfo)
add_subdirectory("${OH_MODULE_DIR}/rnoh-gesture-handler/src/main/cpp" ./gesture-handler)
add_subdirectory("${OH_MODULE_DIR}/rnoh-image-picker/src/main/cpp" ./image-picker)
add_subdirectory("${OH_MODULE_DIR}/rnoh-datetime-picker/src/main/cpp" ./datetime-picker)
add_subdirectory("${OH_MODULE_DIR}/rnoh-flash-list/src/main/cpp" ./flash-list)
add_subdirectory("${OH_MODULE_DIR}/rnoh-svg/src/main/cpp" ./svg)
add_subdirectory("${OH_MODULE_DIR}/rnoh-lottie/src/main/cpp" ./lottie)
# RNOH_END: add_package_subdirectories

file(GLOB GENERATED_CPP_FILES "./generated/*.cpp")
add_library(rnoh_app SHARED
    ${GENERATED_CPP_FILES}
    "./PackageProvider.cpp"
    "${RNOH_CPP_DIR}/RNOHAppNapiBridge.cpp"
)

target_link_libraries(rnoh_app PUBLIC rnoh)

# RNOH_BEGIN: link_packages
target_link_libraries(rnoh_app PUBLIC rnoh_linear_gradient)
target_link_libraries(rnoh_app PUBLIC rnoh_webview)
target_link_libraries(rnoh_app PUBLIC rnoh_safe_area)
target_link_libraries(rnoh_app PUBLIC rnoh_async_storage)
target_link_libraries(rnoh_app PUBLIC rnoh_netinfo)
target_link_libraries(rnoh_app PUBLIC rnoh_gesture_handler)
target_link_libraries(rnoh_app PUBLIC rnoh_image_picker)
target_link_libraries(rnoh_app PUBLIC rnoh_datetime_picker)
target_link_libraries(rnoh_app PUBLIC rnoh_flash_list)
target_link_libraries(rnoh_app PUBLIC rnoh_svg)
target_link_libraries(rnoh_app PUBLIC rnoh_lottie)
# RNOH_END: link_packages