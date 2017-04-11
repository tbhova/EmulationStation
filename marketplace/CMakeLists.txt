project("marketplace")

set(marketplace_SOURCES
        )
set(marketplace_HEADERS
        )

include_directories(${COMMON_INCLUDE_DIRS} ../marketplace/src)
add_library(marketplace STATIC ${marketplace_SOURCES} ${marketplace_HEADERS})
target_link_libraries(marketplace ${COMMON_LIBRARIES})
