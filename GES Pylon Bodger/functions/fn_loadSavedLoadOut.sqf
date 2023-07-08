if(lbCurSel SAVEDLOADOUTSLIST == -1)exitWith{hint "Please select a loadout"};
_name = SAVEDLOADOUTSLIST lbText (lbCurSel SAVEDLOADOUTSLIST);


_savedLoadOuts = profileNamespace getVariable "savedBodgedLoadOuts";

_fnc_applyLoadOut = compile (SAVEDLOADOUTSLIST lbData (lbCurSel SAVEDLOADOUTSLIST));
 
if ((_savedLoadOuts get _name) get "numPylons" != count (getAllPylonsInfo editingVehicle))
 exitWith{[]spawn{
		hint "Pylon count mismatch";
		sleep 10;
		hintSilent ""
		};
	};
[editingVehicle] call _fnc_applyLoadOut;
prioritiesArray = editingVehicle getVariable ["pylonPriority", []]; 
[]spawn{
hint "Applied Saved Loadout!";
sleep 10;
hintSilent ""
};