#===============================================================================
set(CORE_LIST base database control qisis system socet dev)

get_subdirectory_list(${CMAKE_CURRENT_LIST_DIR} modules)

# build core into isis library
add_isis_module(${CORE_LIB_NAME} ${CORE_LIST})

# remove duplicates so we dont build to the core targets twice
foreach(core ${CORE_LIST})
  list(REMOVE_ITEM modules "${CMAKE_CURRENT_LIST_DIR}/${core}")
endforeach()

foreach( mod ${modules} )
  string(REPLACE "${CMAKE_CURRENT_LIST_DIR}/" "" strippedmod ${mod})
  add_isis_module(${strippedmod} ${strippedmod})
endforeach()


