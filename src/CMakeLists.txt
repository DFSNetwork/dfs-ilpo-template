project(dfsilpotemplate)

set(EOSIO_WASM_OLD_BEHAVIOR "Off")
find_package(eosio.cdt)

add_contract( dfsilpotemplate dfsilpotemplate dfsilpotemplate.cpp )
target_include_directories( dfsilpotemplate PUBLIC ${CMAKE_SOURCE_DIR}/../include )
target_ricardian_directory( dfsilpotemplate ${CMAKE_SOURCE_DIR}/../ricardian )