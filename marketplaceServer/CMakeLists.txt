project("marketplace")

set(marketplace_SOURCES
        )
set(marketplace_HEADERS
        )

include_directories(${COMMON_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR}/src)
add_library(marketplaceServer STATIC ${marketplace_SOURCES} ${marketplace_HEADERS})
target_link_libraries(marketplaceServer ${COMMON_LIBRARIES})
