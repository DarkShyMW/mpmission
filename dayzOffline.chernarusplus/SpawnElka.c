void SpawnElka()
{
	ref array<string> giftbox_small = {"Giftbox_Small_1","Giftbox_Small_2","Giftbox_Small_3","Giftbox_Small_4"};
	ref array<string> giftbox_medium = {"Giftbox_Medium_1","Giftbox_Medium_2","Giftbox_Medium_3","Giftbox_Medium_4"};
	ref array<string> giftbox_large = {"Giftbox_Large_1","Giftbox_Large_2","Giftbox_Large_3","Giftbox_Large_4"};
	
	ref array<string> gift1 = {"Ammo_new_12gaImbalanced","Ammo_new_12gaImbalancedSlug","Ammo_new_308WinImbalanced","Ammo_new_357Imbalanced"};
	ref array<string> gift2 = {"Ammo_new_380Imbalanced","Ammo_new_45AcpImbalanced","Ammo_new_545x39Imbalanced","Ammo_new_556x45Imbalanced"};
	ref array<string> gift3 = {"Ammo_new_762x39Imbalanced","Ammo_new_762x54Imbalanced","Ammo_new_9x19Imbalanced","Ammo_new_9x39Imbalanced"};
	ref array<string> gift4 = {"AmmoBox_new_12gaImbalanced","AmmoBox_new_12gaImbalancedSlug","AmmoBox_new_22Imbalanced","AmmoBox_new_308WinImbalanced"};
	//и так далее можно рефов понаделать чтобы подарков много было
	
	vector pos_elka = Vector(4862.0, 0, 6701.0); //центр проверки для ESP
	ref array<Object> nearest_objects = new array<Object>;
	ref array<CargoBase> proxy_cargos = new array<CargoBase>;
	GetGame().GetObjectsAtPosition ( pos_elka, 1000, nearest_objects, proxy_cargos ); //радиус поиска для ESP
	
	for ( int i = 0; i < nearest_objects.Count(); i++ )
	{
		Object nearest_object = nearest_objects.Get(i);
		if ( nearest_object.IsInherited( ChristmasTree_Green ) ) //класснейм ёлки поменять на свой
		{
			Building Elka = Building.Cast(nearest_object);			
			int angle; float tpX; float tpZ; vector pos; vector position; 
			
			pos = Elka.GetPosition();
			float tpY = pos[1];
			
			//1 КОРОБКА
			angle = Math.RandomInt(1,360);
			tpX = pos[0] + Math.RandomFloatInclusive(2, 2.5) * Math.Cos(angle); //расстояние от ёлки покрутить можно чтобы красиво раскладывалось
			tpZ = pos[2] + Math.RandomFloatInclusive(2, 2.5) * Math.Sin(angle);
			position = Vector(tpX,tpY,tpZ);
			ItemBase giftbox_one = GetGame().CreateObject( giftbox_small.GetRandomElement(), position ); 	///создается коробка из списка giftbox_small с названием giftbox_one
			giftbox_one.GetInventory().CreateInInventory( gift1.GetRandomElement() ); 						///в инвентарь giftbox_one спавним предмет из списка gift1
///			giftbox_one.GetInventory().CreateInInventory( gift3.GetRandomElement() );						///если будет место в инвентаре, можно продолжать спавнить в giftbox_one подарки из любого списка
///			giftbox_one.GetInventory().CreateInInventory( gift4.GetRandomElement() );

			//2 КОРОБКА
			angle = Math.RandomInt(1,360);
			tpX = pos[0] + Math.RandomFloatInclusive(2, 2.5) * Math.Cos(angle); //расстояние от ёлки покрутить можно чтобы красиво раскладывалось
			tpZ = pos[2] + Math.RandomFloatInclusive(2, 2.5) * Math.Sin(angle);
			position = Vector(tpX,tpY,tpZ);
			ItemBase giftbox_two = GetGame().CreateObject( giftbox_medium.GetRandomElement(), position ); 	///создается коробка из списка giftbox_medium с названием giftbox_two
			giftbox_two.GetInventory().CreateInInventory( gift2.GetRandomElement() ); 						///в инвентарь giftbox_two спавним предмет из списка gift2
			giftbox_two.GetInventory().CreateInInventory( gift1.GetRandomElement() );
			
			//3 КОРОБКА
			angle = Math.RandomInt(1,360);
			tpX = pos[0] + Math.RandomFloatInclusive(2, 2.5) * Math.Cos(angle); //расстояние от ёлки покрутить можно чтобы красиво раскладывалось
			tpZ = pos[2] + Math.RandomFloatInclusive(2, 2.5) * Math.Sin(angle);
			position = Vector(tpX,tpY,tpZ);
			ItemBase giftbox_three = GetGame().CreateObject( giftbox_large.GetRandomElement(), position ); 	///создается коробка из списка giftbox_large с названием giftbox_three
			giftbox_three.GetInventory().CreateInInventory( gift3.GetRandomElement() ); 					///в инвентарь giftbox_three спавним предмет из списка gift3
			giftbox_three.GetInventory().CreateInInventory( gift1.GetRandomElement() );
			giftbox_three.GetInventory().CreateInInventory( gift2.GetRandomElement() );
			
			//4 КОРОБКА
			angle = Math.RandomInt(1,360);
			tpX = pos[0] + Math.RandomFloatInclusive(2, 2.5) * Math.Cos(angle); //расстояние от ёлки покрутить можно чтобы красиво раскладывалось
			tpZ = pos[2] + Math.RandomFloatInclusive(2, 2.5) * Math.Sin(angle);
			position = Vector(tpX,tpY,tpZ);
			ItemBase giftbox_four = GetGame().CreateObject( giftbox_small.GetRandomElement(), position ); 	///создается коробка из списка giftbox_small с названием giftbox_four
			giftbox_four.GetInventory().CreateInInventory( gift4.GetRandomElement() ); 						///в инвентарь giftbox_four спавним предмет из списка gift4
			
			/////и т.д.
		};
	}
}