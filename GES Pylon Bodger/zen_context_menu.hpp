class zen_context_menu_actions 
{
    class GES_pylonBodger
    {
        displayName = "Pylon Bodger";
        icon = "\a3\modules_f_curator\data\portraitcasmissile_ca.paa";
        statement = "[_hoveredEntity]call GES_fnc_menuEditPylons";
        condition = "if(typeName _hoveredEntity isEqualTo 'GROUP')exitWith{false}; [configFile >> ""CfgVehicles"" >> typeOf _hoveredEntity >> ""Components"" >> ""TransportPylonsComponent""] call BIS_fnc_getCfgIsClass";
        priority = 5;
    };
};