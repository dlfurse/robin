#########################################
# macro to define and install libraries #
#########################################

macro( robin_library name )

	foreach( dependency ${robin_${name}_dependencies} )
		list( APPEND robin_${name}_dependency_names _robin_${dependency} )
	endforeach( dependency )
	
	foreach( base ${robin_${name}_headers} )
		list( APPEND robin_${name}_header_files ${CMAKE_CURRENT_SOURCE_DIR}/${robin_${name}_directory}/${base} )
	endforeach( base )
	
	foreach( base ${robin_${name}_sources} )
		list( APPEND robin_${name}_source_files ${CMAKE_CURRENT_SOURCE_DIR}/${robin_${name}_directory}/${base} )
	endforeach( base )
	
	include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/${robin_${name}_directory} )
	
	add_library( _robin_${name} SHARED ${robin_${name}_header_files} ${robin_${name}_source_files} )
	target_link_libraries( _robin_${name} ${robin_${name}_dependency_names} ${robin_external_libraries} )
	
	install( FILES ${robin_${name}_header_files} DESTINATION include )
	
	install( TARGETS _robin_${name} DESTINATION lib )

endmacro( robin_library )

###########################################
# macro to define and install executables #
###########################################

macro( robin_executables name )

	foreach( dependency ${robin_${name}_dependencies} )
		list( APPEND robin_${name}_dependency_names _robin_${dependency} )
	endforeach( dependency )
	
	foreach( program ${robin_${name}_programs} )
		add_executable( ${program} ${CMAKE_CURRENT_SOURCE_DIR}/${robin_${name}_directory}/${program}.cc )
		target_link_libraries( ${program} ${robin_${name}_dependency_names} ${robin_external_libraries} )
		install( TARGETS ${program} DESTINATION bin )
	endforeach( program )
	
endmacro( robin_executables )

####################################
# macro to define and install json #
####################################

macro( robin_json name )

	foreach( base ${robin_${name}_files} )
		list( APPEND robin_${name}_file_files ${CMAKE_CURRENT_SOURCE_DIR}/${robin_${name}_directory}/${base} )
	endforeach( base )
	
	install( FILES ${robin_${name}_file_files} DESTINATION json )
	
endmacro( robin_json )

