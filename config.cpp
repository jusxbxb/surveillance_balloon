class CfgPatches
{
	class Surveillance_Balloon
	{
		units[] = {"Surveillance Balloon"};	//All the new vehicles/units you've created in cfgVehicles
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"A3_characters_F"};
	};
};

class CfgVehicles
{
	class Helicopter{};
	class Helicopter_Base_F: Helicopter {};
	class UAV_01_base_F: Helicopter_Base_F {
		//class Reflectors{}; //no lights yet so this is empty
		startDuration=3;
		armor=20;
		altFullForce=10000;
		alfNoForce=12000;
		maxSpeed=20;
		precision=15;
		steerAheadSimul=0.5;
		steerAheadPlan=0.69999999;
		predictTurnPlan=2;
		predictTurnSimul=1.5;
		liftForceCoef=1;
		cyclicAsideForceCoef=0.05; //default 2.0
		cyclicForwardForceCoef=1.2;
		bodyFrictionCoef=1.30000001; //does this slow the movement down?
		backRotorForceCoef=5;
		fuelCapacity=10000;
		maxFordingDepth=0.30000001;
		threat[]={0.1,0.1,0.1};
		maxMainRotorDive=0;
		minMainRotorDive=0;
		neutralMainRotorDive=0;
		gearRetracting=0;
		mainRotorSpeed=-7;
		backRotorSpeed=0.5; //does this affect the turning rate?
		tailBladeVertical=0;
		radarTargetSize=2.0;
		visualTargetSize=2.0;
		irTarget=0;
		lockDetectionSystem=0;
		incomingMissileDetectionSystem=0;
		weapons[]=
		{
			"Laserdesignator_pilotCamera"
		};	
		magazines[]=
		{
			"Laserbatteries"
		};
		irScanRangeMin=0;
		irScanRangeMax=0;
		irScanToEyeFactor=1;
	
		
		class pilotCamera
		{
 
			class OpticsIn
			{
				class Wide //Defining the different zoom options
					{
						opticsDisplayName="W";
						initAngleX=0;
						minAngleX=-30;
						maxAngleX=30;
						initAngleY=0;
						minAngleY=-100;
						maxAngleY=100;
						initFov=0.5;
						minFov=0.5;
						maxFov=0.5;
						directionStabilized=1;
						visionMode[]=
						{
							"Normal",
							"NVG",
							"Ti"
						};
						thermalMode[]={0,1};
						gunnerOpticsModel="A3\drones_f\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_wide_F.p3d";
					};
					class Medium: Wide
					{
						opticsDisplayName="M";
						initFov=0.1;
						minFov=0.1;
						maxFov=0.1;
						gunnerOpticsModel="A3\drones_f\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_medium_F.p3d";
					};
					class Narrow: Wide
					{
						opticsDisplayName="N";
						initFov=0.025;
						minFov=0.025;
						maxFov=0.025;
						gunnerOpticsModel="A3\drones_f\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_narrow_F.p3d";
					};
					
					class Close: Wide
					{
						opticsDisplayName="C";
						initFov=0.01;
						minFov=0.01;
						maxFov=0.01;
						gunnerOpticsModel="A3\drones_f\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_narrow_F.p3d";
					};
					
					class Super: Wide
					{
						opticsDisplayName="S";
						initFov=0.005;
						minFov=0.005;
						maxFov=0.005;
						gunnerOpticsModel="A3\drones_f\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_narrow_F.p3d";
					};
				};
				class OpticsOut
				{
					class Monocular
					{
						initAngleX=0;
						minAngleX=-30;
						maxAngleX=30;
						initAngleY=0;
						minAngleY=-100;
						maxAngleY=100;
						initFov=1.1;
						minFov=0.133;
						maxFov=1.1;
						visionMode[]=
						{
							"Normal",
							"NVG"
						};
						gunnerOpticsModel="";
						gunnerOpticsEffect[]={};
					};
				};
				
			}
 
			minTurn		= -90;	// yaw limits
			maxTurn		=  90;	// yaw limits
			initTurn	=   0;	// initial yaw angle
			minElev		= -90;	// pitch limits
			maxElev		=  90;	// pitch limits
			initElev	=   0;	// initial pitch angle
			maxXRotSpeed = 0.5;	// yawing speed
			maxYRotSpeed = 0.5;	// pitching speed
			pilotOpticsShowCursor = 1; // to show aimCursor (is useful to see plane direction)
			controllable = 1;	// set false to have static camera
	};

	//Derive Faction-specific classes: OPFOR, BLUFOR and INDEPENDENT
	class O_UAV_01_F: UAV_01_base_F {};
	class Surveillance_Balloon_O: O_UAV_01_F
	{
		displayName = "Surveillance Balloon (OPFOR)";
		author		= "jusxbxb";
		model 		= "\surveillanceballoon_jsx\surveillanceballoon_v3.p3d";
		icon		= "\surveillanceballoon_jsx\icons\surveillanceballoon_icon.paa";
		isUav=1; 
		uavCameraDriverPos="pip_pilot_pos";        
		uavCameraDriverDir="pip_pilot_dir";        
		uavCameraGunnerPos="PiP0_pos";        
		uavCameraGunnerDir="PiP0_dir";
		extCameraPosition[] = {0, 5, -30};
		extCameraParams[] = { 0.5, 10, 50, 0.5, 1, 10, 30, 0, 1 }; 
		editorPreview="\surveillanceballoon_jsx\data\surveillanceballoon_editorPreview.paa";
		camouflage=10;
		
	};
	
	class B_UAV_01_F: UAV_01_base_F {};
	class Surveillance_Balloon_B: B_UAV_01_F
	{
		displayName = "Surveillance Balloon (BLUFOR)";
		author		= "jusxbxb";
		model 		= "\surveillanceballoon_jsx\surveillanceballoon_v3.p3d";
		icon		= "\surveillanceballoon_jsx\icons\surveillanceballoon_icon.paa";
		isUav=1; 
		uavCameraDriverPos="pip_pilot_pos";        
		uavCameraDriverDir="pip_pilot_dir";        
		uavCameraGunnerPos="PiP0_pos";        
		uavCameraGunnerDir="PiP0_dir";
		extCameraPosition[] = {0, 5, -30};
		extCameraParams[] = { 0.5, 10, 50, 0.5, 1, 10, 30, 0, 1 }; 
		editorPreview="\surveillanceballoon_jsx\data\surveillanceballoon_editorPreview.paa";
		camouflage=10;
		
	};

	class I_UAV_01_F: UAV_01_base_F {};	
	class Surveillance_Balloon_I: I_UAV_01_F
	{
		displayName = "Surveillance Balloon (Independent)";
		author		= "jusxbxb";
		model 		= "\surveillanceballoon_jsx\surveillanceballoon_v3.p3d";
		icon		= "\surveillanceballoon_jsx\icons\surveillanceballoon_icon.paa";
		isUav=1; 
		uavCameraDriverPos="pip_pilot_pos";        
		uavCameraDriverDir="pip_pilot_dir";        
		uavCameraGunnerPos="PiP0_pos";        
		uavCameraGunnerDir="PiP0_dir";
		extCameraPosition[] = {0, 5, -30};
		extCameraParams[] = { 0.5, 10, 50, 0.5, 1, 10, 30, 0, 1 }; 
		editorPreview="\surveillanceballoon_jsx\data\surveillanceballoon_editorPreview.paa";
		camouflage=10;
	}						
};
