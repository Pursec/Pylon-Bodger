_count = ctRowCount PYLONPRIORITYTABLE;
for "_i" from 0 to _count -1 do{
	prioritiesArray set [_i, PYLONPRIORITYTABLE ctValue _i]
};

editingVehicle setPylonsPriority prioritiesArray;
editingVehicle setVariable["pylonPriority", prioritiesArray, true];
PYLONPRIORITYTABLE call GES_fnc_populatePriorityMenu;
[]spawn{
hint "Set new priorities!";
sleep 10;
hintSilent ""
};
