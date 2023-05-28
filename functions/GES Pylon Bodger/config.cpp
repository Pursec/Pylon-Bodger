#include "GESPylonUI.hpp"

class cfgPatches
{
    class GES_PylonLoadOutUI
    {
        units[] = {"GES_Module_PylonLoadOut"};
        requiredVersion = 1;
        requiredAddons[] = {"A3_Modules_F", "A3_3DEN"};
    };
};

class CfgFactionClasses
{
    class GES_PylonLoadOut
    {
        displayName = "[GES] Pylons";
        priority = 8;
        side = 7;
    };
};

class CfgVehicles
{
    class Logic;
    class Module_F: Logic
    {
        class AttributesBase
        {
            class Default;
            class Edit;
            class Combo;
            class Checkbox;
            class CheckboxNumber;
            class ModuleDescription;
            class Units;
        };
    };

    class GES_Module_PylonLoadOut: Module_F
    {
        author = "Goose";
        curatorCanAttach = 1;
        scope = 1;
        scopeCurator = 2;
        displayName = "Plyon Bodger";
        category = "GES_PylonLoadOut";
        function = "GES_fnc_moduleEditPylons";
        functionPriority = 1;
        isGlobal = 1;
        isTriggerActivated = 0;
        curatorInfoType = "";
    };
};

class CfgFunctions
{
	class GES
	{
		class loadVehiclePylons
		{
			file = "\GES\functions";
			class loadVehiclePylons{};
		};
        class moduleEditPylons
		{
			file = "\GES\functions";
			class moduleEditPylons{};
		};
        class searchNSort
		{
			file = "\GES\functions";
			class searchNSort{};
		};
        class generatePylonMagazinesArray
        {
            file = "\GES\functions";
            class generatePylonMagazinesArray{};
        };
        class updatePylonMagazineList
		{
			file = "\GES\functions";
			class updatePylonMagazineList{};
		};
        class updateSelectedPylons
		{
			file = "\GES\functions";
			class updateSelectedPylons{};
		};
        
	};
};