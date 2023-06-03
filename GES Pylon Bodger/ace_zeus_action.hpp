class ACE_ZeusActions
{
    class ZeusUnits
    {
        class GES_pylonBodger
        {
            displayName = "Pylon Bodger";
            condition = "count (curatorSelected select 0) == 1 && {[configFile >> ""CfgVehicles"" >> typeOf (curatorSelected select 0 select 0) >> ""Components"" >> ""TransportPylonsComponent""] call BIS_fnc_getCfgIsClass;}";
            statement = "with uiNameSpace do {[(curatorSelected select 0) select 0] call GES_fnc_menuEditPylons}";
            icon = "\a3\modules_f_curator\data\portraitcasmissile_ca.paa";
        };
    };
};

