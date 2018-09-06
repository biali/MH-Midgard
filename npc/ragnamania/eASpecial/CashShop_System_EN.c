// Cash Shop System GaiaRO
// ==============================================================================

// MapFlags
// *********************************************************************

itemmall	mapflag	nomemo
itemmall	mapflag	nosave	SavePoint
itemmall	mapflag	nowarp
itemmall	mapflag	nowarpto
itemmall	mapflag	noreturn
itemmall	mapflag	noicewall
itemmall	mapflag	nobranch
itemmall	mapflag	nopenalty
itemmall	mapflag	noteleport

// MapFlags
// *********************************************************************

alberta	mapflag	vending_cell
alberta	mapflag	autotrade

// Vending Zone Controler
// *********************************************************************

-	script	Vending_Engine	-1,{
	end;

OnInit:
	setcell "alberta",89,52,89,52,cell_noboards,1;
	setcell "alberta",87,52,87,52,cell_noboards,1;
	setcell "alberta",91,52,91,52,cell_noboards,1;
	setcell "alberta",91,54,91,54,cell_noboards,1;
	setcell "alberta",91,56,91,56,cell_noboards,1;
	setcell "alberta",91,58,91,58,cell_noboards,1;
	setcell "alberta",89,70,89,70,cell_noboards,1;
	setcell "alberta",91,72,91,72,cell_noboards,1;
	setcell "alberta",91,74,91,74,cell_noboards,1;
	setcell "alberta",91,76,91,76,cell_noboards,1;
	setcell "alberta",91,78,91,78,cell_noboards,1;
	setcell "alberta",91,80,91,80,cell_noboards,1;
	setcell "alberta",91,82,91,82,cell_noboards,1;
	setcell "alberta",91,84,91,84,cell_noboards,1;
	setcell "alberta",91,86,91,86,cell_noboards,1;
	setcell "alberta",91,88,91,88,cell_noboards,1;
	setcell "alberta",91,90,91,90,cell_noboards,1;
	setcell "alberta",91,92,91,92,cell_noboards,1;
	setcell "alberta",91,94,91,94,cell_noboards,1;
	setcell "alberta",91,96,91,96,cell_noboards,1;
	setcell "alberta",91,98,91,98,cell_noboards,1;
	setcell "alberta",91,100,91,100,cell_noboards,1;
	setcell "alberta",91,102,91,102,cell_noboards,1;
	setcell "alberta",91,104,91,104,cell_noboards,1;
	setcell "alberta",91,106,91,106,cell_noboards,1;
	setcell "alberta",91,108,91,108,cell_noboards,1;
	setcell "alberta",91,110,91,110,cell_noboards,1;
	setcell "alberta",93,110,93,110,cell_noboards,1;
	setcell "alberta",95,110,95,110,cell_noboards,1;
	setcell "alberta",97,110,97,110,cell_noboards,1;
	setcell "alberta",99,110,99,110,cell_noboards,1;
	setcell "alberta",99,112,99,112,cell_noboards,1;
	setcell "alberta",99,114,99,114,cell_noboards,1;
	setcell "alberta",99,116,99,116,cell_noboards,1;
	setcell "alberta",99,118,99,118,cell_noboards,1;
	setcell "alberta",99,120,99,120,cell_noboards,1;
	setcell "alberta",99,122,99,122,cell_noboards,1;
	setcell "alberta",99,124,99,124,cell_noboards,1;
	setcell "alberta",99,126,99,126,cell_noboards,1;
	setcell "alberta",99,128,99,128,cell_noboards,1;
	setcell "alberta",99,130,99,130,cell_noboards,1;
	setcell "alberta",99,132,99,132,cell_noboards,1;
	setcell "alberta",99,134,99,134,cell_noboards,1;
	setcell "alberta",99,136,99,136,cell_noboards,1;
	setcell "alberta",99,138,99,138,cell_noboards,1;
	setcell "alberta",99,140,99,140,cell_noboards,1;
	setcell "alberta",99,142,99,142,cell_noboards,1;
	setcell "alberta",99,144,99,144,cell_noboards,1;
	setcell "alberta",99,146,99,146,cell_noboards,1;
	setcell "alberta",99,148,99,148,cell_noboards,1;
	setcell "alberta",99,157,99,157,cell_noboards,1;
	setcell "alberta",99,159,99,159,cell_noboards,1;
	setcell "alberta",99,161,99,161,cell_noboards,1;
	setcell "alberta",99,163,99,163,cell_noboards,1;
	setcell "alberta",97,163,97,163,cell_noboards,1;
	setcell "alberta",95,163,95,163,cell_noboards,1;
	setcell "alberta",93,163,93,163,cell_noboards,1;
	setcell "alberta",91,163,91,163,cell_noboards,1;
	setcell "alberta",89,163,89,163,cell_noboards,1;
	setcell "alberta",99,172,99,172,cell_noboards,1;
	setcell "alberta",97,172,97,172,cell_noboards,1;
	setcell "alberta",95,172,95,172,cell_noboards,1;
	setcell "alberta",93,172,93,172,cell_noboards,1;
	setcell "alberta",91,172,91,172,cell_noboards,1;
	setcell "alberta",89,172,89,172,cell_noboards,1;
	setcell "alberta",99,174,99,174,cell_noboards,1;
	setcell "alberta",99,176,99,176,cell_noboards,1;
	setcell "alberta",99,182,99,182,cell_noboards,1;
	setcell "alberta",99,184,99,184,cell_noboards,1;
	setcell "alberta",99,186,99,186,cell_noboards,1;
	setcell "alberta",99,188,99,188,cell_noboards,1;
	setcell "alberta",99,190,99,190,cell_noboards,1;
	setcell "alberta",99,192,99,192,cell_noboards,1;
	setcell "alberta",99,194,99,194,cell_noboards,1;
	setcell "alberta",99,196,99,196,cell_noboards,1;
	setcell "alberta",99,198,99,198,cell_noboards,1;
	setcell "alberta",99,200,99,200,cell_noboards,1;
	setcell "alberta",99,202,99,202,cell_noboards,1;
	setcell "alberta",99,204,99,204,cell_noboards,1;
	setcell "alberta",100,43,100,43,cell_noboards,1;
	setcell "alberta",98,43,98,43,cell_noboards,1;
	setcell "alberta",96,43,96,43,cell_noboards,1;
	setcell "alberta",94,43,94,43,cell_noboards,1;
	setcell "alberta",92,43,92,43,cell_noboards,1;
	setcell "alberta",90,43,90,43,cell_noboards,1;
	setcell "alberta",88,43,88,43,cell_noboards,1;
	setcell "alberta",100,45,100,45,cell_noboards,1;
	setcell "alberta",100,47,100,47,cell_noboards,1;
	setcell "alberta",100,49,100,49,cell_noboards,1;
	setcell "alberta",100,101,100,101,cell_noboards,1;
	setcell "alberta",100,99,100,99,cell_noboards,1;
	setcell "alberta",100,97,100,97,cell_noboards,1;
	setcell "alberta",100,95,100,95,cell_noboards,1;
	setcell "alberta",100,93,100,93,cell_noboards,1;
	setcell "alberta",100,91,100,91,cell_noboards,1;
	setcell "alberta",100,89,100,89,cell_noboards,1;
	setcell "alberta",100,87,100,87,cell_noboards,1;
	setcell "alberta",100,85,100,85,cell_noboards,1;
	setcell "alberta",100,83,100,83,cell_noboards,1;
	setcell "alberta",100,81,100,81,cell_noboards,1;
	setcell "alberta",100,79,100,79,cell_noboards,1;
	setcell "alberta",100,77,100,77,cell_noboards,1;
	setcell "alberta",100,75,100,75,cell_noboards,1;
	setcell "alberta",100,73,100,73,cell_noboards,1;
	setcell "alberta",100,71,100,71,cell_noboards,1;
	setcell "alberta",100,69,100,69,cell_noboards,1;
	setcell "alberta",100,67,100,67,cell_noboards,1;
	setcell "alberta",100,65,100,65,cell_noboards,1;
	setcell "alberta",104,60,104,60,cell_noboards,1;
	setcell "alberta",104,53,104,53,cell_noboards,1;
	setcell "alberta",102,101,102,101,cell_noboards,1;
	setcell "alberta",104,101,104,101,cell_noboards,1;
	setcell "alberta",106,101,106,101,cell_noboards,1;
	setcell "alberta",108,111,108,111,cell_noboards,1;
	setcell "alberta",108,113,108,113,cell_noboards,1;
	setcell "alberta",108,115,108,115,cell_noboards,1;
	setcell "alberta",108,117,108,117,cell_noboards,1;
	setcell "alberta",108,119,108,119,cell_noboards,1;
	setcell "alberta",108,121,108,121,cell_noboards,1;
	setcell "alberta",108,123,108,123,cell_noboards,1;
	setcell "alberta",108,125,108,125,cell_noboards,1;
	setcell "alberta",108,127,108,127,cell_noboards,1;
	setcell "alberta",108,129,108,129,cell_noboards,1;
	setcell "alberta",108,131,108,131,cell_noboards,1;
	setcell "alberta",108,133,108,133,cell_noboards,1;
	setcell "alberta",108,135,108,135,cell_noboards,1;
	setcell "alberta",108,137,108,137,cell_noboards,1;
	setcell "alberta",108,139,108,139,cell_noboards,1;
	setcell "alberta",108,141,108,141,cell_noboards,1;
	setcell "alberta",108,143,108,143,cell_noboards,1;
	setcell "alberta",108,145,108,145,cell_noboards,1;
	setcell "alberta",108,147,108,147,cell_noboards,1;
	setcell "alberta",108,149,108,149,cell_noboards,1;
	setcell "alberta",108,151,108,151,cell_noboards,1;
	setcell "alberta",108,153,108,153,cell_noboards,1;
	setcell "alberta",108,155,108,155,cell_noboards,1;
	setcell "alberta",108,157,108,157,cell_noboards,1;
	setcell "alberta",108,159,108,159,cell_noboards,1;
	setcell "alberta",108,161,108,161,cell_noboards,1;
	setcell "alberta",108,163,108,163,cell_noboards,1;
	setcell "alberta",108,165,108,165,cell_noboards,1;
	setcell "alberta",108,167,108,167,cell_noboards,1;
	setcell "alberta",108,169,108,169,cell_noboards,1;
	setcell "alberta",108,171,108,171,cell_noboards,1;
	setcell "alberta",108,173,108,173,cell_noboards,1;
	setcell "alberta",108,175,108,175,cell_noboards,1;
	setcell "alberta",108,226,108,226,cell_noboards,1;
	setcell "alberta",108,224,108,224,cell_noboards,1;
	setcell "alberta",108,222,108,222,cell_noboards,1;
	setcell "alberta",108,220,108,220,cell_noboards,1;
	setcell "alberta",108,218,108,218,cell_noboards,1;
	setcell "alberta",108,216,108,216,cell_noboards,1;
	setcell "alberta",108,214,108,214,cell_noboards,1;
	setcell "alberta",108,212,108,212,cell_noboards,1;
	setcell "alberta",108,210,108,210,cell_noboards,1;
	setcell "alberta",108,208,108,208,cell_noboards,1;
	setcell "alberta",108,206,108,206,cell_noboards,1;
	setcell "alberta",108,204,108,204,cell_noboards,1;
	setcell "alberta",108,202,108,202,cell_noboards,1;
	setcell "alberta",108,200,108,200,cell_noboards,1;
	setcell "alberta",108,198,108,198,cell_noboards,1;
	setcell "alberta",108,196,108,196,cell_noboards,1;
	setcell "alberta",108,194,108,194,cell_noboards,1;
	setcell "alberta",108,192,108,192,cell_noboards,1;
	setcell "alberta",108,190,108,190,cell_noboards,1;
	setcell "alberta",108,188,108,188,cell_noboards,1;
	setcell "alberta",108,186,108,186,cell_noboards,1;
	setcell "alberta",108,184,108,184,cell_noboards,1;
	setcell "alberta",108,182,108,182,cell_noboards,1;
	setcell "alberta",106,226,106,226,cell_noboards,1;
	setcell "alberta",104,226,104,226,cell_noboards,1;
	setcell "alberta",102,226,102,226,cell_noboards,1;
	// Prontera
	setcell "prontera",148,27,163,192,cell_noboards,1;
	end;
}

// Warps ItemMall Auctions
// *********************************************************************

itemmall,179,49,0	script	imall01	45,1,1,{
	switch( @TerraGirl_out )
	{
		case 2: warp "morocc",166,87; break;
		case 3: warp "geffen",128,65; break;
		case 4: warp "payon",168,103; break;
		case 5: warp "pay_arche",58,147; break;
		case 6: warp "alberta",115,67; break;
		case 7: warp "izlude",123,97; break;
		case 8: warp "aldebaran",135,112; break;
		case 9: warp "xmas",139,134; break;
		case 10: warp "comodo",216,136; break;
		case 11: warp "yuno",167,185; break;
		case 12: warp "amatsu",194,99; break;
		case 13: warp "gonryun",164,115; break;
		case 14: warp "umbala",119,135; break;
		case 15: warp "niflheim",214,184; break;
		case 16: warp "louyang",231,98; break;
		case 17: warp "jawaii",248,137; break;
		case 18: warp "ayothaya",197,173; break;
		case 19: warp "einbroch",57,201; break;
		case 20: warp "lighthalzen",155,87; break;
		case 21: warp "einbech",195,127; break;
		case 22: warp "hugel",109,150; break;
		case 23: warp "rachel",133,115; break;
		case 24: warp "veins",208,106; break;
		case 25: warp "moscovia",233,192; break;
		case 26: warp "mid_camp",202,289; break;
		case 27: warp "brasilis",193,221; break;
		case 28: warp "manuk",279,208; break;
		case 29: warp "splendide",194,174;
		default: warp "prontera",155,182; break;
	}
	end;
}

itemmall,21,37,0	duplicate(imall01)	imall02	45,1,1
quiz_02,354,77,0	duplicate(imall01)	imall03	45,1,1
quiz_02,162,393,0	duplicate(imall01)	imall04	45,1,1
quiz_02,345,393,0	duplicate(imall01)	imall05	45,1,1
quiz_02,51,390,0	duplicate(imall01)	imall06	45,1,1
quiz_02,254,390,0	duplicate(imall01)	imall07	45,1,1

// Stylist Item
// *********************************************************************

function	script	SetPalete	{
	switch( getarg(0) )
	{
		case 1:
			if( Palete_1 )
			{
				setlook 1, Palete_1_HS;
				setlook 6, Palete_1_HC;
				setlook 7, Palete_1_CT;
				set SkinColor, Palete_1_Skin;
				specialeffect2 462;
			}

			break;
		case 2:
			if( Palete_2 )
			{
				setlook 1, Palete_2_HS;
				setlook 6, Palete_2_HC;
				setlook 7, Palete_2_CT;
				set SkinColor, Palete_2_Skin;
				specialeffect2 462;
			}

			break;
	}
	
	return;
}

// Cash Shops - Tiendas
// *********************************************************************

-	cashshop	CashShop_HeadGearA	-1,2237:500,5056:500,5101:500,5134:800,5147:850,5148:850,5180:850,5190:900,5200:900,5209:900,5302:900,5336:900,5337:900,5338:900,5339:900,5346:900,5352:950,5400:950,5412:950,5438:950,5439:950,5440:950,5441:950,5203:1000,5282:1000,5405:1000,5422:1000,5426:1000,5427:1000,5429:1000,5437:1000,5443:1000,5444:1000,5447:1000,5448:1000,5449:1000,5450:1000,5458:1000,5472:1000,5473:1000,5474:1000,5475:1000,5480:1000,5489:1000,5522:1000,5530:1000,5531:1000,5536:1000,5563:1000,5499:1200,5511:1200,5519:1200,5523:1200,5524:1200,5525:1200,5528:1200,5534:1200,5813:1200,5020:1500,5054:1500,5102:1500,5206:1500,5406:1500,5407:1500,5411:1500,5436:1500,5446:1500,5457:1500,5501:1500,5537:1500,5538:1500,5548:1500,5557:1500,5558:1500,5562:1500,5566:1500,5572:1500,5579:1500,5591:1500,5140:2000,5227:2000,5228:2000,5229:2000,5235:2000,5236:2000,5237:2000,5238:2000,5239:2000,5240:2000,5241:2000,5242:2000,5272:2000,5287:2000,5332:2000
-	cashshop	CashShop_HeadGearB	-1,5333:2000,5335:2000,5370:2000,5371:2000,5380:2000,5402:2000,5413:2000,5465:2000,5466:2000,5468:2000,5477:2000,5478:2000,5500:2000,5520:2000,5592:2000,5100:3000,5135:3000,5188:3000,5189:3000,5191:3000,5192:3000,5193:3000,5194:3000,5195:3000,5196:3000,5197:3000,5198:3000,5258:3000,5285:3000,5303:3000,5322:3000,5382:3000,5383:3000,5414:3000,5469:3000,5470:3000,5479:3000,5503:3000,5506:3000,5507:3000,5508:3000,5509:3000,5510:3000,5512:3000,5513:3000,5514:3000,5515:3000,5526:3000,5529:3000,5535:3000,5539:3000,5545:3000,5546:3000,5549:3000,5550:3000,5554:3000,5555:3000,5556:3000,5569:3000,5570:3000,5573:3000,5581:3000,5582:3000,5585:3000,5588:3000,5589:3000,5598:3000,5599:3000,5139:4000,5186:4000,5254:4000,5260:4000,5304:4000,5316:4000,5381:4000,5387:4000,5390:4000,5403:4000,5404:4000,5416:4000,5417:4000,5430:4000,5482:4000,5521:4000,5527:4000,5532:4000,5567:4000,5593:4000,5822:4000,5418:4500,5496:4500
-	cashshop	CashShop_HeadGearC	-1,5149:5000,5179:5000,5184:5000,5213:5000,5214:5000,5243:5000,5311:5000,5319:5000,5334:5000,5359:5000,5410:5000,5568:5000,5143:6000,5146:6000,5152:6000,5183:6000,5230:6000,5231:6000,5232:6000,5233:6000,5234:6000,5252:6000,5253:6000,5263:6000,5270:6000,5294:6000,5354:6000,5355:6000,5365:6000,5385:6000,5397:6000,5409:6000,5471:6000,5495:6000,5502:6000,5505:6000,5151:7000,5182:7000,5225:7000,5259:7000,5286:7000,5293:7000,5298:7000,5305:7000,5491:7000,5098:8000,5099:8000,5103:8000,5129:8000,5130:8000,5208:8000,5256:8000,5257:8000,5261:8000,5262:8000,5271:8000,5284:8000,5289:8000,5291:8000,5296:8000,5300:8000,5307:8000,5310:8000,5317:8000,5360:8000,5361:8000,5396:8000,5485:8000,5497:8000,5498:8000,5533:8000,5568:8000,5131:9000,5133:9000,5153:9000,5185:9000,5187:9000,5220:9000,5255:9000,5288:9000,5379:9000,5388:9000
-	cashshop	CashShop_HeadGearD	-1,5132:10000,5273:10000,5274:10000,5275:10000,5276:10000,5283:10000,5292:10000,5312:10000,5314:10000,5358:10000,5367:10000,5389:10000,5401:10000,5565:10000,5137:11000,5138:11000,5212:11000,5226:11000,5210:12000,5277:12000,5324:12000,5362:12000,5372:12000,5373:12000,5313:13000,5378:13000,5467:13000,5547:13000,5142:14000,5278:14000,5364:14000,5393:14000
-	cashshop	CashShop_HeadGearE	-1,5181:15000,5211:15000,5340:15000,5341:15000,5342:15000,5343:15000,5344:15000,5345:15000,5421:15000,5464:15000,5315:16000,5325:16000,5357:17000,5363:17000,5420:17000,5375:18000,5376:18000,5377:18000,5800:18000,8907:18000,8908:18000,8909:18000,8910:18000,8911:18000,8912:18000
-	cashshop	CashShop_HeadGearF	-1,5462:20000,5463:20000,5490:20000,2204:22000,5423:22000,5564:23000,2202:25000,5483:28000,5374:30000,5518:30000,5574:30000,5580:30000,5594:30000,5596:30000,5597:30000
-	cashshop	CashShop_Donation	-1,1228:300,13412:500,13413:500

function	script	DoTestHats	{
	set @BView, getlook(3);
	set @TView, getlook(4);
	set @MView, getlook(5);
	addtimer 1000, "Terra Girl#1::OnLeave";

	set @Menu$,"";
	for( set @i, 0; @Hats[@i] != 0; set @i, @i + 1 )
		set @Menu$, @Menu$ + getitemname(@Hats[@i]) + ":";
	
	set @Menu$, @Menu$ + "Terminar";
	set @Option, 0;

	while( @Option != @i )
	{
		mes "[^FFA500Kafra Shop^000000]";
		mes "Select the Hat you want to test you.";
		next;
		set @Option, select(@Menu$) - 1;
		if( @Option < @i )
		{
			set @Equip, getiteminfo(@Hats[@Option], 5);
			set @View, getiteminfo(@Hats[@Option], 11);
			
			if( @Equip != -1 && @View > 0 )
			{
				changelook 3,0;
				changelook 4,0;
				changelook 5,0;

				if( @Equip & 1 ) changelook 3,@View;
				if( @Equip & 256 ) changelook 4,@View;
				if( @Equip & 512 ) changelook 5,@View;
			}
		}
	}
	
	mes "[^FFA500Kafra Shop^000000]";
	mes "I hope you found some Hat for you. again talk if you want to buy one.";
	close;
}

itemmall,179,84,4	script	Head Gear Shop N::PremiumShopHGN	721,{
	mes "[^FFA500Kafra Shop^000000]";
	mes "Weapon CashShop And Weekly 50% Sale Headgear Promo.";
	close;
	
	mes "This is the News section for this Month in Head Gears!!.";
	next;
	if( select("Skip to the Store: prove the Weapon") == 2 )
	{
		cleararray @Hats[0],0,127;
		setarray @Hats[0],0;
		callfunc "DoTestHats";
		end;
	}

	mes "[^FFA500Kafra Shop^000000]";
	mes "Close this window to access the store, Luck!!";
	close2;
	callshop "CashShop_Donation",0;
	end;
}

itemmall,183,84,4	script	Head Gear Shop A::PremiumShopHGA	112,{
	mes "[^FFA500Kafra Shop^000000]";
	mes "This list details the first part of the basis of headgears 500-5000 Cash Points";
	next;
	if( select("Skip to the Store: prove the Hats") == 2 )
	{
		cleararray @Hats[0],0,127;
		setarray @Hats[0],2237,5056,5101,5134,5147,5148,5180,5190,5200,5209,5302,5336,5337,5338,5339,5346,5352,5400,5412,5438,5439,5440,5441,5203,5282,5405,5422,5426,5427,5429,5437,5443,5444,5447,5448,5449,5450,5458,5472,5473,5474,5475,5480,5489,5522,5530,5531,5536,5563,5499,5511,5519,5523,5524,5525,5528,5534,5813,5020,5054,5102,5206,5406,5407,5411,5436,5446,5457,5501,5537,5538,5548,5557,5558,5562,5566,5572,5579,5591,5140,5227,5228,5229,5235,5236,5237,5238,5239,5240,5241,5242,5272,5287,5332;
		callfunc "DoTestHats";
		end;
	}

	mes "[^FFA500Kafra Shop^000000]";
	mes "Close this window to access the store, Luck!";
	close2;
	callshop "CashShop_HeadGearA",0;
	end;
}

itemmall,187,84,4	script	Head Gear Shop B::PremiumShopHGB	113,{
	mes "[^FFA500Kafra Shop^000000]";
	mes "This list details the second part of the basis of headgears 500-5000 Cash Points";
	next;
	if( select("Skip to the Store: prove the Hats") == 2 )
	{
		cleararray @Hats[0],0,127;
		setarray @Hats[0],5333,5335,5370,5371,5380,5402,5413,5465,5466,5468,5477,5478,5500,5520,5592,5100,5135,5188,5189,5191,5192,5193,5194,5195,5196,5197,5198,5258,5285,5303,5322,5382,5383,5414,5469,5470,5479,5503,5506,5507,5508,5509,5510,5512,5513,5514,5515,5526,5529,5535,5539,5545,5546,5549,5550,5554,5555,5556,5569,5570,5573,5581,5582,5585,5588,5589,5598,5599,5139,5186,5254,5260,5304,5316,5381,5387,5390,5403,5404,5416,5417,5430,5482,5521,5527,5532,5567,5593,5822,5418,5496;
		callfunc "DoTestHats";
		end;
	}

	mes "[^FFA500Kafra Shop^000000]";
	mes "Close this window to access the store, Luck!!";
	close2;
	callshop "CashShop_HeadGearB",0;
	end;
}

itemmall,191,84,4	script	Head Gear Shop C::PremiumShopHGC	114,{
	mes "[^FFA500Kafra Shop^000000]";
	mes "This list details headgears between 5000-10000 cash Points..";
	next;
	if( select("Skip to the Store: prove the Hats") == 2 )
	{
		cleararray @Hats[0],0,127;
		setarray @Hats[0],5149,5179,5184,5213,5214,5243,5311,5319,5334,5359,5410,5568,5143,5146,5152,5183,5230,5231,5232,5233,5234,5252,5253,5263,5270,5294,5354,5355,5365,5385,5397,5409,5471,5495,5502,5505,5151,5182,5225,5259,5286,5293,5298,5305,5491,5098,5099,5103,5129,5130,5208,5256,5257,5261,5262,5271,5284,5289,5291,5296,5300,5307,5310,5317,5360,5361,5396,5485,5497,5498,5533,5568,5131,5133,5153,5185,5187,5220,5255,5288,5379,5388;
		callfunc "DoTestHats";
		end;
	}

	mes "[^FFA500Kafra Shop^000000]";
	mes "Close this window to access the store, Luck!";
	close2;
	callshop "CashShop_HeadGearC",0;
	end;
}

itemmall,167,84,4	script	Head Gear Shop D::PremiumShopHGD	115,{
	mes "[^FFA500Kafra Shop^000000]";
	mes "This list details headgears between 10000-15000 cash Points.";
	next;
	if( select("Skip to the Store:prove the Hats") == 2 )
	{
		cleararray @Hats[0],0,127;
		setarray @Hats[0],5132,5273,5274,5275,5276,5283,5292,5312,5314,5358,5367,5389,5401,5565,5137,5138,5212,5226,5210,5277,5324,5362,5372,5373,5313,5378,5467,5547,5142,5278,5364,5393;
		callfunc "DoTestHats";
		end;
	}

	mes "[^FFA500Kafra Shop^000000]";
	mes "Close this window to access the store, Luck!!";
	close2;
	callshop "CashShop_HeadGearD",0;
	end;
}

itemmall,171,84,4	script	Head Gear Shop E::PremiumShopHGE	116,{
	mes "[^FFA500Kafra Shop^000000]";
	mes "This list details headgears between 15000-20000 cash Points.";
	next;
	if( select("Skip to the Store: prove the Hats") == 2 )
	{
		cleararray @Hats[0],0,127;
		setarray @Hats[0],5181,5211,5340,5341,5342,5343,5344,5345,5421,5464,5315,5325,5357,5363,5420,5375,5376,5377,5800,8907,8908,8909,8910,8911,8912;
		callfunc "DoTestHats";
		end;
	}

	mes "[^FFA500Kafra Shop^000000]";
	mes "Close this window to access the store, Luck!";
	close2;
	callshop "CashShop_HeadGearE",0;
	end;
}

itemmall,175,84,4	script	Head Gear Shop F::PremiumShopHGF	117,{
	mes "[^FFA500Kafra Shop^000000]";
	mes "This list details of the 20,000 cash headgears Points on.";
	next;
	if( select("Skip to the Store: prove the Hats") == 2 )
	{
		cleararray @Hats[0],0,127;
		setarray @Hats[0],5462,5463,5490,2204,5423,5564,2202,5483,5374,5518,5574,5580,5594,5596,5597;
		callfunc "DoTestHats";
		end;
	}

	mes "[^FFA500Kafra Shop^000000]";
	mes "Close this window to access the store, Luck!";
	close2;
	callshop "CashShop_HeadGearF",0;
	end;
}

-	cashshop	CashShop_Potions	-1,12118:20,12119:20,12120:20,12121:20,12257:20,12274:50,12275:50,12298:50,12299:50,13830:20,13831:20,13832:20,13833:20,14534:20,14535:30,14536:50,14537:50,14538:20,14541:20,14542:30,14543:20,14544:30,13995:150,13989:150,14004:300,13759:100,13760:100,13761:100,13762:100

itemmall,174,66,3	script	Potions Shop::PremiumShopPotions	749,{
	mes "[^FFA500Potions Shop^000000]";
	mes "The Alchemy section contains a good variety of potions..";
	mes "Close this window to access the store, Luck!!!";
	close2;
	callshop "CashShop_Potions",0;
	end;
}

-	cashshop	CashShop_Foods	-1,682:30,683:30,684:50,12122:30,12123:30,12124:40,12198:20,12202:60,12203:60,12204:60,12205:60,12206:60,12207:60,12247:50,12706:10,12707:10,12708:10

itemmall,185,66,5	script	Food Shop::PremiumShopFood	886,{
	mes "[^FFA500Food Shop^000000]";
	mes "Enjoy these special dishes that will increase your skills in battle.";
	mes "Close this window to access the store, Luck!!";
	close2;
	callshop "CashShop_Foods",0;
	end;
}

-	cashshop	CashShop_GiftBox	-1,644:20,664:20,665:20,666:20,667:20,12025:20,12026:20,12104:75,12105:320,12106:500,12107:320,12108:15,12110:20,12111:40

itemmall,185,77,7	script	Gift Shop::PremiumShopGift	803,{
	mes "[^FFA500Gift Shop^000000]";
	mes "A good section to buy gifts for any occasion.";
	mes "Close this window to access the store, Luck!!!";
	close2;
	callshop "CashShop_GiftBox",0;
	end;
}

-	cashshop	CashShop_Accesory	-1,2765:900,2766:900,2767:900,2768:900,2769:900,2770:900,2771:900,2638:2000,2639:2000,2663:3000,2664:3000,2665:3000,2666:3000,2667:3000,2673:3000,2682:4000,2683:4000,2684:4000,2685:4000,2640:8000,2708:15000

itemmall,174,77,1	script	Accesory Shop::PremiumShopAccesory	828,{
	mes "[^FFA500Accesory Shop^000000]";
	mes "Ah, you like accessories and jewelry. than good.";
	mes "Close this window to access the store, Luck!!";
	close2;
	callshop "CashShop_Accesory",0;
	end;
}

-	cashshop	CashShop_Scrolls	-1,14588:25,14589:25,14590:25,686:12,687:17,688:12,689:17,690:12,691:17,692:12,693:17,694:12,695:17,696:7,697:10,698:7,699:10,700:7,12000:10,12001:7,12002:10,12003:7,12114:20,12115:20,12116:20,12117:20,12215:15,12216:15,12217:15,12218:15,12219:15,12220:15,14512:30,14513:30,14514:30,14515:15,14516:15,14517:20,14518:20,14519:20,14520:20,14521:15,14593:10,14594:20


itemmall,180,62,4	script	Scroll Shop::PremiumShopScroll	64,{
	mes "[^FFA500Scroll Shop^000000]";
	mes "Mistress of Magic, these scrolls will help in the battle.";
	mes "Close this window to access the store, Luck!!!";
	close2;
	callshop "CashShop_Scrolls",0;
	end;
}

-	cashshop	CashShop_Special	-1,7619:800,7620:800,6240:1100,6241:1100,6225:1400,6226:1400,12103:2000,12208:1000,12210:1000,7776:1500,7621:100,12209:100,12211:100,12212:20,12214:100,14527:30,14582:30,14583:30,14584:30,14585:30,12213:10000

itemmall,170,71,2	script	Special Shop::PremiumShopSpecial	861,{
	mes "[^FFA500Special Shop^000000]";
	mes "This is the list of special articles, helpful tools for all time.";
	mes "Close this window to access the store, Luck!";
	close2;
	callshop "CashShop_Special",0;
	end;
}

-	cashshop	CashShop_Equipment	-1,2356:1500,2415:1500,2511:1500,1725:1500,1244:1500,2546:1500,2441:1500,2358:1500

itemmall,189,72,6	script	Equipment Shop::PremiumShopEquipment	734,{
	mes "[^FFA500Equipment Shop^000000]";
	mes "This section contains equipment for your characters";
	mes "Close this window to access the store, Luck!!!";
	close2;
	callshop "CashShop_Equipment",0;
	end;
}

-	cashshop	CashShop_WoE	-1,8936:2000,8937:2000,8938:2000,8939:2000,8940:2000,8941:2000,8942:2000,8943:2000,8944:2000,8945:2000,8946:2000,8947:2000,8948:2000

itemmall,192,59,2	script	WoE Shop::PremiumShopWoE	884,{
	mes "[^FFA500WoE Shop^000000]";
	mes "This section contains resources you can use in WoE or GvG maps only.";
	mes "Close this window to access the store, Luck!!!";
	close2;
	callshop "CashShop_WoE",0;
	end;
}

-	cashshop	CashShop_FreyaSet	-1,5306:20000,2533:20000,2369:25000,2428:20000

itemmall,167,59,6	script	Freya Shop::PremiumShopFreya	752,{
	mes "[^FFA500Freya Shop^000000]";
	mes "The Set Freya, all parts are available for any map ^ FF0000EXCEPTO armor that is not allowed in PVP or GVG maps including WoE ^ 000000.";
	mes "Close this window to access the store, Luck!";
	close2;
	callshop "CashShop_FreyaSet",0;
	end;
}

-	cashshop	CashShop_RentalA	-1,12936:2000,12939:2000,12940:2000,12942:2000,12943:2000,12944:2000,12945:2000,12946:2000,12953:2000,12954:2000,12955:2000,12956:2000,12957:2000,12958:2000,12959:2000,12960:2000,12961:2000,12962:2000,12963:2000,12964:2000,13502:2000,13503:2000,13504:2000,13506:2000,13507:2000,13508:2000,13509:2000,13510:2000,13513:2000,13514:2000,13766:2000,13767:2000,13768:2000,13769:2000,13770:2000,13771:2000,13772:2000,13773:2000,13774:2000,13775:2000,13783:2000,13784:2000,13953:2000,13955:2000,13956:2000,13957:2000,13959:2000,12941:3000,13505:3000,13511:3000,13512:3000,13958:3000,12935:5000,12937:5000,12938:5000,13954:5000
-	cashshop	CashShop_RentalB	-1,12947:4000,12948:4000,12949:4000,12950:4000,12951:4000,12952:4000,13776:4000,13778:4000,13779:4000,13780:4000,13781:4000,13782:4000,13777:6000
-	cashshop	CashShop_RentalC	-1,13785:300,13786:300,13787:300,13788:300,13789:300,13790:300,13791:300,13792:300,13793:300,13794:300,13795:300,13797:300,13798:300,13799:300,13800:300,13801:300,13802:300,13803:300,13796:450
-	cashshop	CashShop_RentalD	-1,14262:50,14263:50,14264:50,14265:50,14266:50,14267:50,13915:50,13916:50,13917:50

// Terra Girl
// *********************************************************************

turbo_room,99,120,5	script	Terra Girl#1	864,{
	mes "[^FFA500Terra Girl^000000]";
	mes "Hi, welcome to the Community.";
	mes "I can help you in today?";
	next;
	switch( select("Normal Service:Services Premium:Shop Ancient WoE:CoinsTerra") )
	{
		case 1:
			mes "[^FFA500Terra Girl^000000]";
			mes "This is the section of Service Normal, accessible by all users.";
			mes "want access service?";
			next;
			switch( select("^0000FFBank System^000000:^FF0000Auction^000000:^FFA500Emp Breaker Room^000000:^808080Repair Test Room^000000"))
			{
// ************************************* Repair Test Room ******************************************************************************
				case 4:
					mes "[^FFA500Terra Girl^000000]";
					mes "Want to get into the Testing Room for Repairs Second Edition??";
					mes "This is available to all.";
					next;
					if( select("Access to Room: No Thanks") == 2 )
					{
						mes "[^FFA500Terra Girl^000000]";
						mes "Perfect, find me if you occupy some other service.";
						close;
					}

					set @TerraGirl_out, atoi(strnpcinfo(2));
					warp "quiz_02",249,384;
					end;

// ************************************* Empe Breaker Room ******************************************************************************
				case 3:
					mes "[^FFA500Terra Girl^000000]";
					mes "Want to get into the Testing Room for Emperium Breaker?";
					mes "This is available to all.";
					next;
					if( select("Access to Room: No Thanks") == 2 )
					{
						mes "[^FFA500Terra Girl^000000]";
						mes "Perfect, find me if you occupy some other service.";
						close;
					}

					set @TerraGirl_out, atoi(strnpcinfo(2));
					warp "quiz_02",45,383;
					end;

// ************************************* BANCO ******************************************************************************
				case 1:
					set @This_Day, (2008 - gettime(7)) + gettime(8); // Day of the Year From 1/1/2008
					set @Income, 0;
					set @Total_Income, 0;
					if( #kafrabank > 0 && @This_Day > #Bank_LastIncome && #Bank_LastIncome > 0 )
					{ // Calculates Incomes
						for( set .@i, #Bank_LastIncome; .@i <= @This_Day; set .@i, .@i + 1 )
						{
							set @Income, (#kafrabank + @Total_Income) / 10000; // 0.01% Daily Income
							set @Total_Income, @Total_Income + @Income;
						}
					}

					set #Bank_LastIncome, @This_Day; // Reset Income

					mes "[^FFA500Terra Girl^000000]";
					mes "Welcome to Bank service.";
					if( #kafrabank < 1 )
					{
						mes "still does not have a bank account.";
						next;
						set @Option, select("Open an Account...") - 1;
					}
					else
					{
						if( @Total_Income > 1000000000 - #kafrabank )
							set @Total_Income, 1000000000 - #kafrabank;

						mes "Saldo Pasado: ^0000FF" + #kafrabank + "^000000 zeny.";
						mes "Ingresos Diarios (0.1%): ^0000FF" + @Total_Income + "^000000 zeny.";
						set #kafrabank, #kafrabank + @Total_Income;
						mes "Saldo Actual: ^0000FF" + #kafrabank + "^000000 zeny.";
						next;
						set @Option, select("Placing Zeny: Remove Zeny");
					}

					switch( @Option )
					{
						case 0: // Abrir Cuenta
							mes "[^FFA500Terra Girl^000000]";
							mes "In our banking service can open an account with at least 1.000 zeny.";
							mes "Your money is safe with me and earn additional 0.1% daily income.";
							next;
							mes "[^FFA500Terra Girl^000000]";
							mes "With regard want to open the account?";
							next;
						case 1: // Depositar Zeny
							if( @Option == 1 )
							{
								mes "[^FFA500Terra Girl^000000]";
								mes "Tell me how much you want to deposit.";
								mes "Minimum 1.000 zeny .";
								mes "Maximum 10.000.000 zeny .";
								next;
							}
							
							input @Amount;
							if( @Amount < 1000 || @Amount > 10000000 )
							{
								mes "[^FFA500Terra Girl^000000]";
								mes "Tell me how much you want to deposit.";
								mes "Minimum 1.000 zeny .";
								mes "Maximum 10.000.000 zeny .";
								close;
							}
							
							if( Zeny < @Amount )
							{
								mes "[^FFA500Terra Girl^000000]";
								mes "You do not have enough Zeny to the indicated cassette.";
								close;
							}

							if( @Amount > 1000000000 - #kafrabank )
							{
								mes "[^FFA500Terra Girl^000000]";
								mes "Zeny maximum you can have in your account is:";
								mes "1.000.000.000 zeny";
								mes "You can not proceed with the deposit.";
								close;
							}

							set Zeny, Zeny - @Amount;
							specialeffect 10;

							mes "[^FFA500Terra Girl^000000]";
							mes "Saldo Pasado: ^0000FF" + #kafrabank + "^000000 zeny.";
							set #kafrabank, #kafrabank + @Amount;
							mes "Tu Dep�sito: ^0000FF" + @Amount + "^000000 zeny.";
							mes "Saldo Actual: ^0000FF" + #kafrabank + "^000000 zeny.";
							break;
						case 2: // Retirar Zeny
							mes "[^FFA500Terra Girl^000000]";
							mes "Tell me how much you want to withdraw.";
							mes "Saldo Actual: ^0000FF" + #kafrabank + "^000000 zeny.";
							mes "1 Minimum zeny .";
							mes "10.000.000 Maximum zeny .";
							next;

							input @Amount;
							if( @Amount < 1 || @Amount > 10000000 )
							{
								mes "[^FFA500Terra Girl^000000]";
								mes "TYour retirement does not respect boundaries.";
								mes "1 Minimum zeny .";
								mes "10.000.000 Maximum zeny .";
								close;
							}
							
							if( #kafrabank < @Amount )
							{
								mes "[^FFA500Terra Girl^000000]";
								mes "You do not have enough Zeny in the retirement account.";
								close;
							}

							if( @Amount > 1000000000 - Zeny )
							{
								mes "[^FFA500Terra Girl^000000]";
								mes "Zeny maximum you can have in your character is::";
								mes "1.000.000.000 zeny";
								mes "You can not proceed with the withdrawal.";
								close;
							}

							set Zeny, Zeny + @Amount;
							specialeffect2 10;

							mes "[^FFA500Terra Girl^000000]";
							mes "Saldo Pasado: ^0000FF" + #kafrabank + "^000000 zeny.";
							set #kafrabank, #kafrabank - @Amount;
							mes "Tu Retiro: ^0000FF" + @Amount + "^000000 zeny.";
							mes "Saldo Actual: ^0000FF" + #kafrabank + "^000000 zeny.";
							break;
					}
					close;
// ************************************* ESTILISTA **************************************************************************
				case 5:
					set @HairStyle, getlook(1);
					set @HairColor, getlook(6);
					set @Clothes, getlook(7);

					mes "[^FFA500Terra Girl^000000]";
					mes "Bienvenido al servicio de estilista, en donde puedo cambiar tu apariencia.";
					mes "En que te puedo ayudar?";
					next;

					switch( select("^FFA500Cambiar mi apariencia^000000:Mi Paleta Favorita 1:Mi Paleta Favorita 2") )
					{
						case 2: // Paleta Favorita 1
							mes "[^FFA500Terra Girl^000000]";
							mes "Dime, que deseas hacer?";
							next;
							switch( select("Abrir Paleta","Guardar Paleta","Comprar Cupones") )
							{
								case 1:
									if( !Palete_1 )
									{
										mes "[^FFA500Terra Girl^000000]";
										mes "No has creado tu Paleta Favorita 1.";
										close;
									}

									setlook 1, Palete_1_HS;
									setlook 6, Palete_1_HC;
									setlook 7, Palete_1_CT;
									set SkinColor, Palete_1_Skin;

									mes "[^FFA500Terra Girl^000000]";
									mes "Esta es tu Paleta Favorita 1.";
									mes "Nos vemos.";
									close;
								case 2:
									set Palete_1, 1;
									set Palete_1_HS, @HairStyle;
									set Palete_1_HC, @HairColor;
									set Palete_1_CT, @Clothes;
									set Palete_1_Skin, SkinColor;

									mes "[^FFA500Terra Girl^000000]";
									mes "Tu estilo actual ha sido guardado en tu Paleta Favorita 1.";
									mes "Nos vemos.";
									close;
								case 3:
									if( !Palete_1 )
									{
										mes "[^FFA500Terra Girl^000000]";
										mes "No has creado tu Paleta Favorita 1.";
										close;
									}

									if( countitem(6046) >= 10 )
									{
										mes "[^FFA500Terra Girl^000000]";
										mes "El m�ximo de cupones que puedes tener es de 10.";
										mes "Cuando gastes algunos, vuelve.";
										close;
									}

									set @Amount, 10 - countitem(6046);
									set @Cost, @Amount * 250;

									mes "[^FFA500Terra Girl^000000]";
									mes "El cupon te permite cambiar tu vestimenta a tu Paleta Favorita 1 en cualquier lugar.";
									mes "Te puedo vender" + @Amount + " cupones en " + @Cost + "z.";
									next;
									if( select("S� por favor:No gracias") == 2 )
									{
										mes "[^FFA500Terra Girl^000000]";
										mes "Un gusto ayudarte.";
										close;
									}

									if( Zeny < @Cost )
									{
										mes "[^FFA500Terra Girl^000000]";
										mes "Que pena, no tienes suficiente dinero.";
										close;
									}

									set Zeny, Zeny - @Cost;
									getitem 6046,@Amount;

									mes "[^FFA500Terra Girl^000000]";
									mes "Aqu� tienes tus cupones. Luce tus dise�os al mundo y suerte!!.";
									close;
							}
						case 3: // Paleta Favorita 2
							mes "[^FFA500Terra Girl^000000]";
							mes "Dime, que deseas hacer?";
							next;
							switch( select("Abrir Paleta","Guardar Paleta","Comprar Cupones") )
							{
								case 1:
									if( !Palete_2 )
									{
										mes "[^FFA500Terra Girl^000000]";
										mes "No has creado tu Paleta Favorita 2.";
										close;
									}

									setlook 1, Palete_2_HS;
									setlook 6, Palete_2_HC;
									setlook 7, Palete_2_CT;
									set SkinColor, Palete_2_Skin;

									mes "[^FFA500Terra Girl^000000]";
									mes "Esta es tu Paleta Favorita 2.";
									mes "Nos vemos.";
									close;
								case 2:
									set Palete_2, 1;
									set Palete_2_HS, @HairStyle;
									set Palete_2_HC, @HairColor;
									set Palete_2_CT, @Clothes;
									set Palete_2_Skin, SkinColor;

									mes "[^FFA500Terra Girl^000000]";
									mes "Tu estilo actual ha sido guardado en tu Paleta Favorita 2.";
									mes "Nos vemos.";
									close;
								case 3:
									if( !Palete_2 )
									{
										mes "[^FFA500Terra Girl^000000]";
										mes "No has creado tu Paleta Favorita 2.";
										close;
									}

									if( countitem(6047) >= 10 )
									{
										mes "[^FFA500Terra Girl^000000]";
										mes "El m�ximo de cupones que puedes tener es de 10.";
										mes "Cuando gastes algunos, vuelve.";
										close;
									}

									set @Amount, 10 - countitem(6047);
									set @Cost, @Amount * 250;

									mes "[^FFA500Terra Girl^000000]";
									mes "El cupon te permite cambiar tu vestimenta a tu Paleta Favorita 2 en cualquier lugar.";
									mes "Te puedo vender" + @Amount + " cupones en " + @Cost + "z.";
									next;
									if( select("S� por favor:No gracias") == 2 )
									{
										mes "[^FFA500Terra Girl^000000]";
										mes "Un gusto ayudarte.";
										close;
									}

									if( Zeny < @Cost )
									{
										mes "[^FFA500Terra Girl^000000]";
										mes "Que pena, no tienes suficiente dinero.";
										close;
									}

									set Zeny, Zeny - @Cost;
									getitem 6047,@Amount;

									mes "[^FFA500Terra Girl^000000]";
									mes "Aqu� tienes tus cupones. Luce tus dise�os al mundo y suerte!!.";
									close;
							}
					}

					mes "[^FFA500Terra Girl^000000]";
					mes "Vamos a trabajar en tu estilo, navega entre las opciones disponibles y busca la combinaci�n que mejor te haga sentir.";
					next;

					// Ranges Definition
					set .@HairS_Min, 0; set .@HairS_Max, 27;
					set .@HairC_Min, 0; set .@HairC_Max, 244;
					set .@ClotC_Min, 0; set .@ClotC_Max, 303;
					// Brown Skin
					set .@BHair_Min, 21; set .@BHair_Max, 40;
					set .@BClot_Min, 304; set .@BClot_Max, 530;
					// User Paletes
					set .@UClot_Min, 0; set .@UClot_Max, 0;

					switch( Class )
					{
						case Job_Priest:
						case Job_High_Priest:
						case Job_Baby_Priest:
							if( Sex == 0 ) {
								set .@UClot_Min, 1001; set .@UClot_Max, 1032;
							} else {
								set .@UClot_Min, 4001; set .@UClot_Max, 4032;
							}
							break;
						case Job_Monk:
						case Job_Champion:
						case Job_Baby_Monk:
							if( Sex == 0 ) {
								set .@UClot_Min, 1101; set .@UClot_Max, 1128;
							} else {
								set .@UClot_Min, 4101; set .@UClot_Max, 4129;
							}
							break;
						case Job_Wizard:
						case Job_High_Wizard:
						case Job_Baby_Wizard:
							if( Sex == 0 ) {
								set .@UClot_Min, 1201; set .@UClot_Max, 1233;
							} else {
								set .@UClot_Min, 4201; set .@UClot_Max, 4235;
							}
							break;
						case Job_Sage:
						case Job_Professor:
						case Job_Baby_Sage:
							if( Sex == 0 ) {
								set .@UClot_Min, 1301; set .@UClot_Max, 1338;
							} else {
								set .@UClot_Min, 4301; set .@UClot_Max, 4339;
							}
							break;
						case Job_Alchem:
						case Job_Creator:
						case Job_Baby_Alchem:
							if( Sex == 0 ) {
								set .@UClot_Min, 1401; set .@UClot_Max, 1428;
							} else {
								set .@UClot_Min, 4401; set .@UClot_Max, 4442;
							}
							break;
						case Job_Assassin:
						case Job_Assassin_Cross:
						case Job_Baby_Assassin:
							if( Sex == 0 ) {
								set .@UClot_Min, 1501; set .@UClot_Max, 1529;
							} else {
								set .@UClot_Min, 4501; set .@UClot_Max, 4530;
							}
							break;
						case Job_Blacksmith:
						case Job_Whitesmith:
						case Job_Baby_Blacksmith:
							if( Sex == 0 ) {
								set .@UClot_Min, 1601; set .@UClot_Max, 1633;
							} else {
								set .@UClot_Min, 4601; set .@UClot_Max, 4633;
							}
							break;
						case Job_Stalker:
							if( Sex == 0 ) {
								set .@UClot_Min, 1701; set .@UClot_Max, 1732;
							} else {
								set .@UClot_Min, 4701; set .@UClot_Max, 4732;
							}
							break;
						case Job_Hunter:
						case Job_Sniper:
						case Job_Baby_Hunter:
							if( Sex == 0 ) {
								set .@UClot_Min, 1801; set .@UClot_Max, 1828;
							} else {
								set .@UClot_Min, 4801; set .@UClot_Max, 4825;
							}
							break;
						case Job_Crusader:
						case Job_Crusader2:
						case Job_Paladin:
						case Job_Paladin2:
						case Job_Baby_Crusader:
						case Job_Baby_Crusader2:
							if( Sex == 0 ) {
								set .@UClot_Min, 1901; set .@UClot_Max, 1932;
							} else {
								set .@UClot_Min, 4901; set .@UClot_Max, 4932;
							}
							break;
						case Job_Knight:
						case Job_Knight2:
						case Job_Lord_Knight:
						case Job_Lord_Knight2:
						case Job_Baby_Knight:
						case Job_Baby_Knight2:
							if( Sex == 0 ) {
								set .@UClot_Min, 2001; set .@UClot_Max, 2034;
							} else {
								set .@UClot_Min, 5001; set .@UClot_Max, 5042;
							}
							break;
						case Job_Dancer:
						case Job_Gypsy:
						case Job_Baby_Dancer:
						case Job_Bard:
						case Job_Clown:
						case Job_Baby_Bard:
							if( Sex == 0 ) {
								set .@UClot_Min, 2101; set .@UClot_Max, 2138;
							} else {
								set .@UClot_Min, 5101; set .@UClot_Max, 5120;
							}
							break;
						case Job_Soul_Linker:
							if( Sex == 0 ) {
								set .@UClot_Min, 2201; set .@UClot_Max, 2220;
							} else {
								set .@UClot_Min, 5201; set .@UClot_Max, 5220;
							}
							break;
						case Job_Star_Gladiator:
						case Job_Star_Gladiator2:
							if( Sex == 0 ) {
								set .@UClot_Min, 2301; set .@UClot_Max, 2320;
							} else {
								set .@UClot_Min, 5301; set .@UClot_Max, 5320;
							}
							break;
						case Job_Gunslinger:
							if( Sex == 0 ) {
								set .@UClot_Min, 2401; set .@UClot_Max, 2412;
							} else {
								set .@UClot_Min, 5401; set .@UClot_Max, 5412;
							}
							break;
					}

					// Starting Styles
					set @NHairC, SkinColor * 21;
					set @NClotC, SkinColor * 304;
					set @NHairS, @HairStyle;

					// Reset Look with vars
					changelook 6, @NHairC;
					changelook 7, @NClotC;

					set @OnStylist, 1; // Using Stylist - Security
					addtimer 1000, "Terra Girl#1::OnLeaveSty";

					while( select("Cambiar Color de Piel:Estilo de Pelo:Color de Pelo:Color de Ropa:^0000FFTerminar^000000") != 5 )
					{
						switch( @menu )
						{
							case 1: // Skin Color
								while( select("Piel Blanca:Piel Morena:^0000FFRegresar^000000") != 3 )
								{
									set @NSkin, @menu - 1;
									if( @NSkin != SkinColor )
									{ // Reset Aparience and Counters
										set SkinColor, @NSkin;
										changelook 6,set(@NHairC, 21 * @NSkin);
										changelook 7,set(@NClotC, 304 * @NSkin);
									}
								}

								break;
							case 2: // Hair Style
								while( select("^FFA500[<] ^000000 Anterior:^FFA500[>] ^000000 Siguiente:^0000FFRegresar^000000") != 3 )
								{
									switch( @menu )
									{
										case 1:
											set @NHairS, @NHairS - 1;
											if( @NHairS < .@HairS_Min ) set @NHairS, .@HairS_Max;
											break;
										case 2:
											set @NHairS, @NHairS + 1;
											if( @NHairS > .@HairS_Max ) set @NHairS, .@HairS_Min;
											break;
									}

									changelook 1,@NHairS;
									dispbottom "[ Model : " + @NHairS + " | " + @NHairC + " | " + @NClotC + " ]";
								}

								break;
							case 3: // Hair Color
								while( select("^FFA500[<] ^000000 Anterior:^FFA500[>] ^000000 Siguiente:^0000FFRegresar^000000") != 3 )
								{
									switch( @menu )
									{
										case 1:
											set @NHairC, @NHairC - 1;
											if( SkinColor == 0 )
											{ // White Skin
												if( @NHairC < .@HairC_Min ) set @NHairC, .@HairC_Max;
												else if( @NHairC == .@BHair_Max ) set @NHairC, .@BHair_Min - 1;
											}
											else
											{ // Brown Skin
												if( @NHairC < .@BHair_Min ) set @NHairC, .@BHair_Max;
											}
											break;
										case 2:
											set @NHairC, @NHairC + 1;
											if( SkinColor == 0 )
											{ // White Skin
												if( @NHairC > .@HairC_Max ) set @NHairC, .@HairC_Min;
												else if( @NHairC == .@BHair_Min ) set @NHairC, .@BHair_Max + 1;
											}
											else
											{ // Brown Skin
												if( @NHairC > .@BHair_Max ) set @NHairC, .@BHair_Min;
											}
											break;
									}

									changelook 6,@NHairC;
									dispbottom "[ Model : " + @NHairS + " | " + @NHairC + " | " + @NClotC + " ]";
								}

								break;
							case 4: // Clothes Color
								while( select("^FFA500[<] ^000000 Anterior:^FFA500[>] ^000000 Siguiente:^0000FFRegresar^000000") != 3 )
								{
									switch( @menu )
									{
										case 1:
											set @NClotC, @NClotC - 1;
											if( SkinColor == 0 )
											{ // White Skin
												if( @NClotC == .@ClotC_Min - 1 )
												{
													if( .@UClot_Max )
														set @NClotC, .@UClot_Max;
													else
														set @NClotC, .@ClotC_Max;
												}
												else if( .@UClot_Min && @NClotC == .@UClot_Min - 1 )
													set @NClotC, .@ClotC_Max;
											}
											else
											{ // Brown Skin
												if( @NClotC < .@BClot_Min ) set @NClotC, .@BClot_Max;
											}
											break;
										case 2:
											set @NClotC, @NClotC + 1;
											if( SkinColor == 0 )
											{ // White Skin
												if( @NClotC == .@ClotC_Max + 1 )
												{
													if( .@UClot_Min )
														set @NClotC, .@UClot_Min;
													else
														set @NClotC, .@ClotC_Min;
												}
												else if( .@UClot_Max && @NClotC == .@UClot_Max + 1 )
													set @NClotC, .@ClotC_Min;
											}
											else
											{ // Brown Skin
												if( @NClotC > .@BClot_Max ) set @NClotC, .@BClot_Min;
											}
											break;
									}

									changelook 7,@NClotC;
									dispbottom "[ Model : " + @NHairS + " | " + @NHairC + " | " + @NClotC + " ]";
								}

								break;
						}
					}

					mes "[^FFA500Terra Girl^000000]";
					mes "Veamos la factura...";
					next;
					set @Cost, 0;

					mes "[^FF0000Factura^000000]";

					if( @NHairS != @HairStyle )
					{
						set @Cost, @Cost + 2500;
						mes "Estilo de Peinado: ^0000FF2.500^000000z.";
					}
					else
						mes "Estilo de Peinado: ^0000FF0^000000 z.";

					if( @NHairC != @HairColor )
					{
						set @Cost, @Cost + 2500;
						mes "Color de Peinado: ^0000FF2.500^000000z.";
					}
					else
						mes "Color de Peinado: ^0000FF0^000000z.";

					if( @NClotC != @Clothes )
					{
						set @Cost, @Cost + 2500;
						mes "Color de Ropa: ^0000FF2.500^000000z.";
					}
					else
						mes "Color de Ropa: ^0000FF0^000000z.";

					mes "^0000FF.... Total Servicio: " + @Cost + " ^000000z.";
					next;

					if( @Cost == 0 )
					{ // No Changes
						mes "[^FFA500Terra Girl^000000]";
						mes "Mmm... parece que prefieres seguir como estabas, pero te v�s genial de todas formas.";
						mes "Suerte!!";

						set @OnStylist, 0;
						deltimer "Terra Girl#1::OnLeaveSty";
						close;
					}

					if( select( "^0000FFPagar por el Cambio^000000","No gracias, no me gust�..." ) == 2 )
					{
						mes "[^FFA500Terra Girl^000000]";
						mes "Que!!? Pero gast� mucho tiempo!!.";
						mes "Bueno, vuelve si cambias de parecer.";

						// Reset Look
						changelook 1,@HairStyle;
						changelook 6,@HairColor;
						changelook 7,@Clothes;

						set @OnStylist, 0;
						deltimer "Terra Girl#1::OnLeaveSty";
						close;
					}

					if( Zeny < @Cost )
					{
						mes "[^FFA500Terra Girl^000000]";
						mes "Que!!? No tienes dinero contigo!?.";
						mes "Gracias por hacerme perder el tiempo";

						// Reset Look
						changelook 1,@HairStyle;
						changelook 6,@HairColor;
						changelook 7,@Clothes;

						set @OnStylist, 0;
						deltimer "Terra Girl#1::OnLeaveSty";
						close;
					}

					set Zeny, Zeny - @Cost;
					set @OnStylist, 0;
					deltimer "Terra Girl#1::OnLeaveSty";

					// Real Set of new Paletes
					setlook 1,@NHairS;
					setlook 6,@NHairC;
					setlook 7,@NClotC;

					mes "[^FFA500Terra Girl^000000]";
					mes "Genial!!, te vez muy bien...";
					mes "Un gusto trabajar para t�.";
					close;
// ************************************* ITEMMALL ***************************************************************************
				case 2:
					mes "[^FFA500Terra Girl^000000]";
					mes "auctions find what players are auctioned and you can make your deals.";
					mes "Close this window to continue.";
					close2;
					OpenAuction;
					end;
			}

			break;
		case 2:
			mes "[^FFA500Terra Girl^000000]";
			mes "This is the section of ^FF0000Service Premium^000000 offered to thos who donate to the community.";
			mes "want access service?";
			mes " ";
			mes "^0000FFhttp://Terragaming-ro.com^000000";
			next;
			switch( select("^4169E1Acess Premium^000000:^FFA500My Points^000000:^0000FFPremium Mall^000000:^FF0000Open Buying Store^000000:Rental item:^008000Character Stats Reallocation^000000") )
			{
				case 1:
					mes "[^FFA500Terra Girl^000000]";
					mes "Premium Account allows you to access special features of the server as:";
					mes "- 10% off Premium";
					mes "- Storage Aditional";
					mes "- Renta item";
					mes "- Minigames, Mining";
					next;
					if( isPremium() == 1 )
					{
						mes "[^FFA500Terra Girl^000000]";
						mes "Your Premium Account expires:";
						mes "^FF0000" + callfunc("Time2Str",##Premium_Tick) + "^000000.";
						next;
					}
					mes "[^FFA500Terra Girl^000000]";
					mes "Turn your account to Premium or extends the current if it already is.";
					mes " ";
					mes "Premium Time: 4 weeks";
					mes "Cash Points : 7500";
					next;
					if( select("Buy Time Premium: Not now") == 2 )
					{
						mes "[^FFA500Terra Girl^000000]";
						mes "No problem.'m at your service.";
						close;
					}
					
					if( ##CASHPOINTS < 7500 )
					{
						mes "[^FFA500Terra Girl^000000]";
						mes "You do not have enough Cash Points.";
						close;
					}
					
					if( isPremium() == 1 )
						set ##Premium_Tick, ##Premium_Tick + 2419200; // Time Extension
					else
						set ##Premium_Tick, gettimetick(2) + 2419200; // New Premium Account
					set ##CASHPOINTS, ##CASHPOINTS - 7500;

					mes "[^FFA500Terra Girl^000000]";
					mes "Congratulations...";
					mes "Remember, your premium account is available for:";
					mes "^FF0000" + callfunc("Time2Str",##Premium_Tick) + "^000000.";
					close;
				case 2:
					mes "[^FFA500Terra Girl^000000]";
					mes "You currently have : ^0000FF" + ##CASHPOINTS + "^000000 Cash Points";
					next;

					set @Cash[0], 0;
					set @Query$, "SELECT `cash_points` FROM `login` WHERE `account_id` = '" + getcharid(3) + "'";
					if( query_sql(@Query$, @Cash) == 0 )
					{
						mes "[^FFA500Terra Girl^000000]";
						mes "There seems to be a problem to check if you have more points to transfer to the game.";
						mes "Report the problem to some ^0000FFGame Master^000000.";
						close;
					}

					if( @Cash[0] <= 0 )
					{
						mes "[^FFA500Terra Girl^000000]";
						mes "You have to transfer points to your account, possibly your donation has not yet been approved or does not report it.";
						mes "Check the Accounts ^0000FFControl Panel^000000.";
						close;
					}

					set @Query$, "UPDATE `login` SET `cash_points` = `cash_points` - '" + @Cash[0] + "' WHERE `account_id` = '" + getcharid(3) + "'";
					query_sql @Query$;
					set ##CASHPOINTS, ##CASHPOINTS + @Cash[0];

					mes "[^FFA500Terra Girl^000000]";
					mes "Have been Transferred ^0000FF" + @Cash[0] + "^000000 to your game account to purchase item.";
					mes "Now you have: ^0000FF" + ##CASHPOINTS + "^000000 Cash Points";
					next;
					mes "[^FFA500Terra Girl^000000]";
					mes "If you have any doubt or question please write to the address:";
					mes "^0000FFgaiaro.staff@gmail.com^000000";
					close;
				case 3:
					mes "[^FFA500Terra Girl^000000]";
					mes "Close this window to send the Item Mall where you can visit all the stores available.";
					close2;
					warp "itemmall",179,52;
					end;
				case 4: // Buying Store Skill =============================================
					mes "[^FFA500Terra Girl^000000]";
					mes "Buying Store skill allows any player to have a store of things you are interested in buying.";
					next;
					mes "[^FFA500Terra Girl^000000]";
					mes "Other players who have these items can come and vendertelos. enables Shop Zeny set limits and prices that you pay for each item.";
					next;
					if( getskilllv("ALL_BUYING_STORE") )
					{
						mes "[^FFA500Terra Girl^000000]";
						mes "Oh, so I can see you already have the ability , excellent!!";
						close;
					}

					mes "[^FFA500Terra Girl^000000]";
					mes "skill premium has a value of 1 Terra's Bronze Coin";
					mes "You are interested in buying it?";
					next;
					if( select("Yes, I would buy the skill: No thanks.") == 2 )
					{
						mes "[^FFA500Terra Girl^000000]";
						mes "If you change your mind just find me, I am at your service.";
						close;
					}

					if( countitem(8905) < 1 )
					{
						mes "[^FFA500Terra Girl^000000]";
						mes "Bronze Coins not have you, remember that these can change the me, for 1000 Cash Points.";
						close;
					}

					delitem 8905,1;
					skill "ALL_BUYING_STORE",2,0;

					mes "[^FFA500Terra Girl^000000]";
					mes "Congratulations, you've learned a new skill. If you are unsure of how to use it, resorts to a Game Master.";
					close;

				case 5:
					mes "[^FFA500Terra Girl^000000]";
					mes "This is the section of Rental Items.";
					mes "You purchase an item that will come in a box.";
					next;
					mes "[^FFA500Terra Girl^000000]";
					mes "When you open the box, time shall begin to run even if you are not connected";
					mes "The item is deleted from the inventory at the end of time";
					next;
					switch( select("^FFA500Build it and Rent it!! ^FF0000(New)^000000:Holiday 1 day:Holiday 7 day:Holiday 14 day:^0000FFDesign Power of Chat^000000") )
					{
					case 1:
						mes "[^FFA500Terra Girl^000000]";
						mes "You can rent here equipment for 1 week, while you get it by normal way. The value in Cash Points of the item depends of the options (type, refine, cards, enchanting) you choose.";
						next;
						mes "[^FFA500Terra Girl^000000]";
						mes "Ok, tell me what do you want to build?";
						next;
						cleararray .@Items[0],0,127;
						cleararray .@Cards[0],0,127;
						set .@Value, 0; // To Calculate Final Rental Value

						switch( select("HeadGears (^0000FF800 cp^000000):Garments (^0000FF800 cp^000000):Armors (^0000FF1200 cp^000000):Footgear (^0000FF800 cp^000000):Accesories (^0000FF800 cp^000000):Shields (^0000FF1000 cp^000000):Weapons (^0000FF400 x Weapon Level^000000)") )
						{
						case 1: // Headgears
							set .@Value, 800;
							setarray .@Items[0],2202,2204,5398,5170,5399,5126,5127,5171;
							setarray .@Cards[0],4438,4379,4288,4229,4041,4296,4169,4122,4177,4052,4258,4354,4110,4271,4278,4087,4161,4343,4269,4412,4366,4434,4195,4188,4112,4364,4046,4206,4127,4311,4185,4358,4039,4223,4336,4411,4010,4261,4260;
							break;
						case 2: // Garment
							set .@Value, 800;
							setarray .@Items[0],2525,2521,2546,2530,2537,2527,2515,2542,2513,2502,2506,2532,2504,2545,2512,2514,2536,2544,2523,2524,2531,2528;
							setarray .@Cards[0],4402,4129,4285,4373,4015,4179,4178,4056,4266,4088,4303,4325,4081,4116,4287,4431,4351,4432,4113,4095,4197,4108,4159,4334,4375,4071,4313,4133,4422,4429,4306,4183,4211,4210,4102;
							break;
						case 3: // Armors
							set .@Value, 1200;
							setarray .@Items[0],2306,2349,2355,2356,2315,2351,2310,2302,2375,2374,2366,2320,2317,2319,2373,2304,2342,2318,2391,2345,2372,2308,2364,2311,2389,2359,2393,2353,2313,2371,2390,2360,2365,2326,2347,2324,2322,2333,2367,2387,2336,2331,2357,2329;
							setarray .@Cards[0],4409,4401,4400,4387,4234,4243,4242,4371,4114,4023,4233,4119,4213,4300,4299,4061,4298,4170,4173,4370,4181,4098,4279,4410,4346,4141,4405,4280,4270,4150,4162,4286,4301,4295,4191,4201,4105,4339,4166,4392,4338,4099,4031,4315,4008,4011,4337,4001,4003,4383,4353,4021,4014,4194,4101,4216,4078,4393,4222,4404,4158,4220,4042,4218,4089,4016,4369,4333,4332,4259,4189,4382;
							break;
						case 4: // FootGears
							set .@Value, 800;
							setarray .@Items[0],2420,2441,2434,2406,2415,2433,2412,2432,2422,2416,2402,2404,2440,2424,2421,2423;
							setarray .@Cards[0],4244,4245,4249,4009,4235,4070,4267,4160,4319,4151,4378,4381,4164,4417,4239,4050,4097,4200,4199,4204,4208,4186,4221,4100,4396,4107,4257,4038,4275,4435;
							break;
						case 5: // Accesorys
							set .@Value, 800;
							setarray .@Items[0],2743,2656,2627,2747,2655,2671,2625,2607,2730,2728,2748,2732,2729,2622,2703,2624,2701,2702,2716,2749,2718,2623,2658,2745,2717,2700,2621,2626,2731,2715,2677;
							setarray .@Cards[0],4252,4344,4347,4356,4215,4327,4212,4262,4293,4040,4272,4385,4154,4349,4349,4152,4423,4149,4418,4283,4377,4355,4331,4437,4232,4103,4321,4433,4139,4091,4027,4265,4193,4079,4196,4084,4205,4036,4093,4256,4238,4237,4077,4073,4389,4048,4175,4033,4294,4436,4187,4391,4219,4326,4230,4416,4228,4044,4415,4022,4227,4424,4224,4028,4282,4209,4053,4348,4264,4034,4190,4051,4064;
							break;
						case 6: // Shield
							set .@Value, 1000;
							setarray .@Items[0],2116,2118,2104,2130,2102,2120,2131,2121,2108,2123,2128,2106,2134,2114,2125,2124,2133,2115;
							setarray .@Cards[0],4253,4032,4248,4013,4138,4240,4075,4074,4217,4439,4322,4413,4045,4231,4136,4124,4067,4090,4420,4207,4066,4309,4314,4083,4414,4120,4059,4059,4226,4304,4340,4397,4058,4012,4254,4277;
							break;
						case 7: // Weapons
							// Value Depends of the Weapon Lvl
							mes "[^FFA500Terra Girl^000000]";
							mes "What kind of weapon do you want to build?";
							next;
							switch( select("1H Axe:2H Axe:1H Spear:2H Spear:1H Sword:2H Sword:Book:Bow:Dagger:Fist:Katar:Maces:Instruments:Staff:Whips:Guns:Fuuma Shurikens") )
							{
							case 1: // 1H Axe
								setarray .@Items[0],1302,1305,1309,1306,1307;
								break;
							case 2: // 2H Axe
								setarray .@Items[0],1375,1352,1363,1358,1371,1364,1369,1355,1376,1377,1366,1365,1367,1368,1361;
								break;
							case 3: // 1H Spear
								setarray .@Items[0],1421,1415,1414,1418,1422,1402,1420,1408,1417,1405,1416;
								break;
							case 4: // 2H Spear
								setarray .@Items[0],1478,1485,1467,1470,1484,1476,1480,1455,1452,1464,1471,1483,1469,1458,1479,1461,1481;
								break;
							case 5: // 1H Sword
								setarray .@Items[0],1108,1140,1134,13405,13400,1132,13414,1137,1105,1133,1149,1143,1128,1145,1131,1141,1138,1130,13404,1111,1125,1127,1144,1114,1136,1148,1102,1139,1147,1120;
								break;
							case 6: // 2H Sword
								setarray .@Items[0],1155,1175,1182,1162,1172,1186,1180,1179,1117,1170,1165,1164,1176,1178,1152,1181,1158,1185,1171;
								break;
							case 7: // Books
								setarray .@Items[0],1573,1562,1551,1550,1568,1571,1569,1557,1570,1564,1558,1561,1565,1559,1572,1560,1552;
								break;
							case 8: // Bow
								setarray .@Items[0],1715,1727,1702,1730,1705,1711,1741,1736,1724,1732,1731,1716,1733,1708,1726,1737,1723,1725,1740,1734,1719,1720;
								break;
							case 9: // Dagger
								setarray .@Items[0],13011,13033,1235,1231,1246,13004,1241,1205,1214,1242,13038,1226,13034,1211,13030,1233,1223,13019,1220,13006,1237,13015,1244,1230,13039,13008,13009,1229,1202,1225,1208,13027,1234,13013,13016,1240,13035,1217,13018,1224,13028,1238;
								break;
							case 10: // Fist
								setarray .@Items[0],1822,1816,1810,1820,1812,1808,1815,1825,1819,1813,1804,1818,1821,1806,1802;
								break;
							case 11: // Katar
								setarray .@Items[0],1271,1265,1270,1266,1269,1255,1251,1253,1275,1278,1276,1277,1262,1260,1264,1263,1268;
								break;
							case 12: // Maces
								setarray .@Items[0],1520,1502,1511,1539,1540,1529,1525,1544,1505,1514,1541,1527,1526,1508,1538,1532,1517,1531;
								break;
							case 13: // Instruments
								setarray .@Items[0],1919,1920,1914,1925,1913,1917,1916,1908,1912,1910,1926,1915,1906,1904,1922,1902;
								break;
							case 14: // Staffs
								setarray .@Items[0],1611,2001,1637,1615,1629,1638,1631,1622,1624,1613,1625,1630,1602,1472,1635,1608,2000,1626,1627,1634,1618,1620,1636,1605,1614,1616,1473;
								break;
							case 15: // Whips
								setarray .@Items[0],1969,1974,1964,1972,1971,1973,1967,1966,1962,1976,1957,1963,1965,1951,1980,1968,1979,1959,1961,1953,1955;
								break;
							case 16: // Guns
								setarray .@Items[0],13155,13150,13159,13103,13152,13161,13157,13153,13105,13156,13167,13106,13162,13165,13170,13164,13154,13101,13169,13107;
								break;
							case 17: // Fuuma Shurikent
								setarray .@Items[0],13305,13300,13302,13304;	
								break;
							}

							setarray .@Cards[0],4140,4062,4043,4018,4094,4246,4247,4307,4320,4214,4428,4390,4063,4289,4368,4284,4202,4153,4297,4171,4388,4082,4125,4182,4069,4180,4004,4421,4176,4118,4251,4360,4002,4316,4020,4026,4080,4323,4165,4157,4060,4155,4156,4072,4163,4345,4019,4362,4115,4035,4268,4065,4292,4291,4350,4184,4006,4076,4030,4055,4341,4057,4126,4317,4106,4203,4440,4167,4255,4085,4310,4007,4329,4335,4024,4380,4104,4192,4005,4017,4068,4130,4312,4273,4117,4406,4025,4092,4037,4394,4086,4225,4111,4427,4398,4395,4172,4308,4049,4029,4096,4281,4274;
							break;
						}

						// Build Item
						set .@MenuI$, "";
						for( set .@i, 0; .@Items[.@i] != 0; set .@i, .@i + 1 )
						{
							if( getiteminfo(.@Items[.@i], 10) > 0 )
								set .@MenuI$, .@MenuI$ + getitemname(.@Items[.@i]) + "[" + getiteminfo(.@Items[.@i], 10) + "]:";
							else
								set .@MenuI$, .@MenuI$ + getitemname(.@Items[.@i]) + ":";
						}

						set .@Item, select(.@MenuI$) - 1;
						setarray .@Card[0], 0, 0, 0, 0;

						if( !checkweight(.@Items[.@Item], 1) )
						{
							mes "[^FFA500Terra Girl^000000]";
							mes "You cannot hold this weapons because of weight limits on your character. Please free some weight.";
							close;
						}

						if( !getitemisequipable(.@Items[.@Item]) )
						{
							mes "[^FFA500Terra Girl^000000]";
							mes "^FF0000WARNING!!^000000";
							mes "This items cannot be used by your class.";
							next;
						}

						set .@MenuC$, "";
						for( set .@i, 0; .@Cards[.@i] != 0; set .@i, .@i + 1 )
							set .@MenuC$, .@MenuC$ + getitemname(.@Cards[.@i]) + ":";

						for( set .@i, 0; .@i < getiteminfo(.@Items[.@Item], 10); set .@i, .@i + 1 )
						{ // Cards
							mes "[^FFA500Terra Girl^000000]";
							mes "Please, choose a card for slot [" + (.@i + 1) + "]";
							mes "Each Card adds ^0000FF150^000000 cp to the Rent Value.";
							next;
							set .@Card[.@i], .@Cards[select(.@MenuC$) - 1];
							set .@Value, .@Value + 150; // Value Per Card
						}

						mes "[^FFA500Terra Girl^000000]";
						mes "You want to build a : ^0000FF" + getitemname(.@Items[.@Item]) + "^000000.";

						if( getitemisrefinable(.@Items[.@Item]) )
						{
							// Set the Safe, Normal and Extended Refine per Item Level.
							setarray .@SRefine[0],4,7,6,5,4;
							setarray .@NRefine[0],7,10,9,7,5;
							setarray .@ERefine[0],9,10,10,9,5;

							if( .@NRefine[getiteminfo(.@Items[.@Item], 13)] != .@ERefine[getiteminfo(.@Items[.@Item], 13)] )
								set .@RefOpt, select("Do not Refine it:Refine it to " + .@SRefine[getiteminfo(.@Items[.@Item], 13)] + " (150 cp):Refine it to " + .@NRefine[getiteminfo(.@Items[.@Item], 13)] + "  (500 cp):Refine it to " + .@ERefine[getiteminfo(.@Items[.@Item], 13)] + " for 2500 Cash Points");
							else
								set .@RefOpt, select("Do not Refine it:Refine it to " + .@SRefine[getiteminfo(.@Items[.@Item], 13)] + " (150 cp):Refine it to " + .@NRefine[getiteminfo(.@Items[.@Item], 13)] + "  (500 cp)");

							switch( .@RefOpt )
							{
							case 1: // Not Refine
								set .@Refine, 0;
								break;
							case 2: // Base Refine
								set .@Refine, .@SRefine[getiteminfo(.@Items[.@Item], 13)];
								set .@Value, .@Value + 150;
								break;
							case 3: // Normal Refine
								set .@Refine, .@NRefine[getiteminfo(.@Items[.@Item], 13)];
								set .@Value, .@Value + 500;
								break;
							case 4: // Extra Refine
								set .@Refine, .@ERefine[getiteminfo(.@Items[.@Item], 13)];
								set .@Value, .@Value + 2500;
								break;
							}

							if( .@RefOpt > 1 )
								mes "It will receive a ^0000FF" + .@Refine + "^000000 refine.";
							else
								mes "It will be not refined.";
						}
						else
						{
							set .@Refine, 0;
							mes "Item is not refinable.";
						}

						if( getiteminfo(.@Items[.@Item], 13) == 0 )
						{ // Armor - Check for Enchanting
							deletearray .@Armor[0],127;
							setarray .@Armor[0],2358,2307,2309,2314,2316,2321,2325,2327,2330,2332,2334,2335,2341,2344,2346,2348,2350,2337,2386,2311,2318,2319,2320,2308,2310,2315,2317,2322,2324,2326,2331,2333,2336,2342,2345,2347,2349,2351,2364,2365,2374,2375,2387,2389,2391,2376,2377,2378,2379,2380,2381,2382,2394,2395,2396;
							for( set .@i, 0; .@i < getarraysize(.@Armor); set .@i, .@i + 1 )
							{
								if( .@Armor[.@i] == .@Items[.@Item] )
									break;
							}

							if( .@i < getarraysize(.@Armor) )
							{ // This item is Enchantable officially
								set .@Enchant, select("Do not Enchant the Armor:Add STR:Add INT:Add DEX:Add AGI:Add VIT:Add LUK") - 1;
								if( .@Enchant > 0 )
								{
									set .@Bonus, select("^0000FF+1^000000 (150 cp):^0000FF+2^000000 (300 cp):^0000FF+3^000000 (450 cp):^0000FF+4^000000 (1450 cp)");
									if( .@Bonus < 4 )
										set .@Value, .@Value + (.@Bonus * 150);
									else
										set .@Value, .@Value + 1450;

									set .@Card[3], 4690 + ( 10 * .@Enchant ) + .@Bonus - 1;
									mes "Enchanted with ^0000FF" + getitemname(.@Card[3]) + "^000000.";
								}
							}
							else
							{ // Extra Enchant +1
								set .@Enchant, select("Do not Enchant the Armor:Add +1 STR (^0000FF1000 cp^000000):Add +1 INT (^0000FF1000 cp^000000):Add +1 DEX (^0000FF1000 cp^000000):Add +1 AGI (^0000FF1000 cp^000000):Add +1 VIT (^0000FF1000 cp^000000):Add +1 LUK (^0000FF1450 cp^000000)") - 1;
								if( .@Enchant > 0 )
								{
									set .@Card[3], 4690 + ( 10 * .@Enchant );
									set .@Value, .@Value + 1000;
									mes "Enchanted with ^0000FF" + getitemname(.@Card[3]) + "^000000.";
								}
							}
						}
						else
							set .@Value, .@Value + (getiteminfo(.@Items[.@Item], 13) * 400); // Extra Value for Weapon Level

						for( set .@i, 0; .@i < getiteminfo(.@Items[.@Item], 10); set .@i, .@i + 1 )
							mes "Card on slot [" + (.@i + 1) + "] ^0000FF" + getitemname(.@Card[.@i]) + "^000000";

						mes "Is this ok?";
						next;

						if( select("I want to rent it 1 week (^0000FF" + .@Value + " cp^000000):No, i just changed my mind...") == 1 )
						{
							if( ##CASHPOINTS < .@Value )
							{
								mes "[^FFA500Terra Girl^000000]";
								mes "I'm sorry, but you don't have enough Cash Points.";
								close;
							}

							mes "[^FFA500Terra Girl^000000]";
							mes "Here is your item.";
							mes "It will be automatic removed from your inventory in one week.";

							set ##CASHPOINTS, ##CASHPOINTS - .@Value;
							rentitem2 .@Items[.@Item],1,.@Refine,0,.@Card[0],.@Card[1],.@Card[2],.@Card[3],604800;
							logmes "Rented " + getitemname(.@Items[.@Item]) + " Details : Ref = " + .@Refine + " Cards = " + .@Card[0] + " " + .@Card[1] + " " + .@Card[2] + " " + .@Card[3];
						}
						else
						{
							mes "[^FFA500Terra Girl^000000]";
							mes "No items received.";
						}
						close;

					case 2: set .@Class$, "C"; break;
					case 3: set .@Class$, "A"; break;
					case 4: set .@Class$, "B"; break;
					case 5: set .@Class$, "D"; break;
					}
					
					mes "[^FFA500Terra Girl^000000]";
					mes "Remember open box only when you are ready to start the rent";
					mes "Carefully read descriptions of the boxes.";
					close2;
					callshop "CashShop_Rental" + .@Class$ + "",0;
					end;
				case 6:
					mes "[^FFA500Terra Girl^000000]";
					mes "Tell me which room you want to access.";
					next;

					set @Option, select("Simon Says:Visual Memory:Memory Hearing");
					set @TerraGirl_out, atoi(strnpcinfo(2));

					mes "[^FFA500Terra Girl^000000]";
					mes "Good luck in your visit, close this window to proceed.";
					close2;
					
					if( isPremium() == 0 )
					{
						npctalk "Sorry, your premium time expired...";
						end;
					}
					
					switch( @Option )
					{
					case 1:
						if( getvariableofnpc(.Simon,"SimonManager") != 0 )
							npctalk "Sorry, the game room is in use...";
						else
							warp "quiz_02",351,75;
						break;

					case 2:
						if( getvariableofnpc(.Status,"MemoryManager") != 0 )
							npctalk "Sorry, the game room is in use...";
						else
							warp "quiz_02",162,390;
						break;

					case 3: 
						if( getvariableofnpc(.Status,"MusicManager") != 0 )
							npctalk "Sorry, the game room is in use...";
						else
							warp "quiz_02",345,389;
						break;
					}
					end;
				case 7:
					mes "[^FFA500Terra Girl^000000]";
					mes "Character Stats Reallocation, you can release 20 stat points to reassign them to your liking.";
					mes "This service can only be used every three months..";
					next;
					if( StatRealloc_DT >= gettimetick(2) )
					{
						mes "[^FFA500Terra Girl^000000]";
						mes "You have already used this service. reuse in You:";
						mes "^0000FF" + callfunc("Time2Str",StatRealloc_DT) + "^000000.";
						close;
					}

					mes "[^FFA500Terra Girl^000000]";
					mes "The value of the service is ^0000FF6.000 Cash Points^000000.";
					mes "Additional, you should not bring Carro, Falcon, Frame, Homunculus or Pet.";
					mes "The weight that you bring should not exceed 100.";
					mes "Want to use this service?";
					next;
					if( select("Yes, I am determined: No, no way") == 2 )
					{
						mes "[^FFA500Terra Girl^000000]";
						mes "I'm here to serve, anything find me again.";
						close;
					}

					if( Weight > 1000 || checkriding() || checkfalcon() || checkcart() || getpetinfo(0) || gethominfo(0) )
					{
						mes "[^FFA500Terra Girl^000000]";
						mes "It seems you did not understand the instructions.";
						mes "You must not bring Carro, Falcon, Frame, Homunculus or Pet.";
						mes "The weight that you bring should not exceed 100.";
						close;
					}

					if( ##CASHPOINTS < 6000 )
					{
						mes "[^FFA500Terra Girl^000000]";
						mes "I'm sorry but not sufficient Cash Points slides with you.";
						mes "The value of the service is ^0000FF6.000 Cash Points^000000.";
						close;
					}
					
					set .@puntos_rt,StatusPoint;
					setarray .@stats_a[1],readparam(bStr),readparam(bAgi),readparam(bVit),readparam(bInt),readparam(bDex),readparam(bLuk);
					setarray .@stats_n$[1],"STR","AGI","VIT","INT","DEX","LUK";

					mes "[^FFA500Terra Girl^000000]";
					mes "These are your current Stats:";
					for( set .@i, 1; .@i <= 6; set .@i, .@i + 1 )
						mes "^FF0000" + .@stats_n$[.@i] + "^000000 : ^0000FF" + .@stats_a[.@i] + "^000000";
					
					next;
					set .@total_stats,0;
					for( set .@i, 1; .@i <= 6; set .@i, .@i + 1 )
					{
						set .@restantes, 20 - .@total_stats;
						if( .@restantes > .@stats_a[.@i] - 1 )
							set .@restantes, .@stats_a[.@i] - 1; // This protect from a user trying to remove more than the minimum value (1)

						mes "[^FFA500Terra Girl^000000]";
						mes "Points to terminate ^FF0000" + .@stats_n$[.@i] + "^000000? (0 - " + .@restantes + ")";
						mes "Currently you ^0000FF" + .@stats_a[.@i] + "^000000 de " + .@stats_n$[.@i] + ".";
						next;
						input .@stats[.@i];
						if( .@stats[.@i] < 0 || .@stats[.@i] > .@restantes )
						{
							mes "[^FFA500Terra Girl^000000]";
							mes "value out of range (0 - " + .@restantes + ")";
							mes "Cancelling..";
							close;
						}
						
						set .@total_stats, .@total_stats + .@stats[.@i];
						if( .@total_stats >= 20 )
							break;
					}

					if( .@total_stats != 20 )
					{
						mes "[^FFA500Terra Girl^000000]";
						mes "You must choose 20 total stat points, you chose only " + .@total_stats + ".";
						mes "Cancelling...";
						close;
					}

					mes "[^FFA500Terra Girl^000000]";
					mes "your stats would be like this:";
					for( set .@i, 1; .@i <= 6; set .@i, .@i + 1 )
					{
						set .@stats_r[.@i], .@stats_a[.@i] - .@stats[.@i];
						if( .@stats[.@i] > 0 )
							mes "^FF0000" + .@stats_n$[.@i] + "^000000 : " + .@stats_a[.@i] + " - " + .@stats[.@i] + " = ^0000FF" + .@stats_r[.@i] + "^000000";
						else
							mes "^FF0000" + .@stats_n$[.@i] + "^000000 : ^0000FF" + .@stats_a[.@i] + "^000000";
					}
					next;
					if( select("To proceed, I want to make the change: I changed my mind, do not want to") == 2 )
					{
						mes "[^FFA500Terra Girl^000000]";
						mes "I am here to serve, anything find me again.";
						close;
					}
					if( .@puntos_rt != StatusPoint )
					{
						mes "[^FFA500Terra Girl^000000]";
						mes "StatusPoints have changed.";
						mes "Cancelling...";
						close;
					}
					if( ##CASHPOINTS < 6000 )
					{
						mes "[^FFA500Terra Girl^000000]";
						mes "I'm sorry but not sufficient Cash Points you behave.";
						mes "The value of the service is Points of Cash ^0000FF15.000 Cash Points^000000.";
						close;
					}
					set ##CASHPOINTS, ##CASHPOINTS - 6000;
					resetstatus; // Reset All Status Points
					set .@St, bStr;
					for( set .@i, 1; .@i <= 6; set .@i, .@i + 1 )
					{
						set .@StatsValue, 0;
						for( set .@j, 1; .@j <= .@stats_r[.@i] - 1; set .@j, .@j + 1 )
						{
							if( .@j >= 115 )
								set .@StatsValue, .@StatsValue + 28;
							else if( .@j >= 110 )
								set .@StatsValue, .@StatsValue + 24;
							else if( .@j >= 105 )
								set .@StatsValue, .@StatsValue + 20;
							else if( .@j >= 100 )
								set .@StatsValue, .@StatsValue + 16;
							else
								set .@StatsValue, .@StatsValue + (1 + ((.@j + 9) / 10));
						}

						set StatusPoint, StatusPoint - .@StatsValue; // Pay Stats Value
						statusup2 .@St, .@stats_r[.@i] - 1; // Increase Stat
						set .@St, .@St + 1; // Move to next Stat
					}
					set StatRealloc_DT, gettimetick(2) + 7776000;

					mes "[^FFA500Terra Girl^000000]";
					mes "Stats Changed.";
					mes "you can make the following change : ^0000FF" + callfunc("Time2Str",StatRealloc_DT) + "^000000.";
					close;
			}
			break;

// ************************************* ANCIENT WOE SHOP ***************************************************************************
		case 3:
			mes "[^FFA500Terra Girl^000000]";
			mes "You need to buy supplies for the ancient battle?";
			mes "I can sell you some at good prices.";
			next;
			
			if( set(.@cID, getbattleflag("ancient_reserved_char_id")) < 1 )
			{
				mes "[^FFA500Terra Girl^000000]";
				mes "It seems that I am not yet authorized to sell items for Ancient.";
				mes "Informate or consultation forum for its implementation.";
				close;
			}

			setarray .@Items[0],   505,  547, 7135, 7136, 7137, 7138, 7139;
			setarray .@Price[0],   650,  500,  400,  400,  200,  200,  800;

			set .@Menu$, "";
			for( set .@i, 0; .@i < 7; set .@i, .@i + 1 )
				set .@Menu$, .@Menu$ + .@Price[.@i] + "z. x Ancient's " + getitemname(.@Items[.@i]) + ":";

			set .@Potion, select(.@Menu$) - 1;

			mes "[^FFA500Terra Girl^000000]";
			mes "So you want to buy " + getitemname(.@Items[.@Potion]) + "...";
			mes "The value per unit is " + .@Price[.@Potion] + " zeny.";
			mes "Remember that they can only be used in Ancient WoE.";
			mes "How many do you want? (1 to 200)";
			next;

			input .@Amount;
			if( .@Amount < 1 || .@Amount > 200 )
			{
				mes "[^FFA500Terra Girl^000000]";
				mes "The amount you ask no I can give you.";
				mes "Remember that you can order from 1 to 200 maximum per purchase.";
				close;
			}

			set .@Cost, .@Price[.@Potion] * .@Amount;
			if( Zeny < .@Cost )
			{
				mes "[^FFA500Terra Girl^000000]";
				mes "You do not have enough money to buy.";
				mes "For your order you need " + .@Cost + " zeny.";
				close;
			}
			
			if( checkweight(.@Items[.@Potion], .@Amount) == 0 )
			{
				mes "[^FFA500Terra Girl^000000]";
				mes "It seems you can not stand the weight of the purchase you want to make.";
				mes "Save some in storage or purchase fewer units.";
				close;
			}

			set Zeny, Zeny - .@Cost;
			getitem2 .@Items[.@Potion],.@Amount,1,0,0,254,0,.@cID&0xffff,(.@cID>>16)&0xffff;
			
			mes "[^FFA500Terra Girl^000000]";
			mes "Here ... Now be careful, and struggle for honor and glory of your Clan.";
			close;

// ************************************* Terra Coins Shop ***************************************************************************
		case 4:
			mes "[^FFA500Terra Girl^000000]";
			mes "Oh ... interested Terra Coins. These coins are a useful way to convert Points into Cash items to trade, and you can come here to buy or sell always the same value.";
			next;

			switch( select("Buy Coins: Sell my Coins: Information") )
			{
				case 1:
					mes "[^FFA500Terra Girl^000000]";
					mes "want to buy coins?";
					mes "You currently have " + ##CASHPOINTS + " Cash Points.";
					next;
					set .@Coin, 8902 + select("Gold Coin x 10.000 Cash Points:Silver Coin x 5.000 Cash Points:Bronze Coin x 1.000 Cash Points");
					set .@Value, 0;

					switch( .@Coin )
					{
						case 8903: set .@Value, 10000; break;
						case 8904: set .@Value, 5000; break;
						case 8905: set .@Value, 1000; break;
					}

					mes "[^FFA500Terra Girl^000000]";
					mes "many " + getitemname(.@Coin) + " deseas comprar?";
					mes "(Minimo 1, Maximo 10)";
					next;
					input .@Amount;

					if( .@Amount < 1 || .@Amount > 10 )
					{
						mes "[^FFA500Terra Girl^000000]";
						mes "Sorry, but I can only sell 1 to 10 Coins at a time.";
						close;
					}

					set .@Cost, .@Amount * .@Value;
					if( ##CASHPOINTS < .@Cost )
					{
						mes "[^FFA500Terra Girl^000000]";
						mes "Points do not have enough cash for the purchase. sorry.";
						mes "The Amount needed is " + .@Cost + " Cash Points.";
						close;
					}

					getitem .@Coin, .@Amount;
					set ##CASHPOINTS, ##CASHPOINTS - .@Cost;

					mes "[^FFA500Terra Girl^000000]";
					mes "Here are your Terra Coins, luck with your business!.";
					break;

				case 2:
					mes "[^FFA500Terra Girl^000000]";
					mes "want to sell coins?";
					mes "You currently have:";
					mes "- " + countitem(8903) + " Gold Coins.";
					mes "- " + countitem(8904) + " Silver Coins.";
					mes "- " + countitem(8905) + " Bronze Coins.";
					next;
					set .@Coin, 8902 + select("Gold Coin x 10.000 Cash Points:Silver Coin x 5.000 Cash Points:Bronze Coin x 1.000 Cash Points");
					set .@Value, 0;

					switch( .@Coin )
					{
						case 8903: set .@Value, 10000; break;
						case 8904: set .@Value, 5000; break;
						case 8905: set .@Value, 1000; break;
					}

					mes "[^FFA500Terra Girl^000000]";
					mes "Many " + getitemname(.@Coin) + " Want to sell me?";
					mes "(Minimo 1, Maximo 10)";
					next;
					input .@Amount;

					if( .@Amount < 1 || .@Amount > 10 )
					{
						mes "[^FFA500Terra Girl^000000]";
						mes "Sorry, but I can only buy 1 to 10 Coins while.";
						close;
					}

					if( countitem(.@Coin) < .@Amount )
					{
						mes "[^FFA500Terra Girl^000000]";
						mes "You do not have enough Coins in your inventory to sell me the number you chose.";
						close;
					}

					set .@Cost, .@Amount * .@Value;
					delitem .@Coin, .@Amount;
					set ##CASHPOINTS, ##CASHPOINTS + .@Cost;

					mes "[^FFA500Terra Girl^000000]";
					mes "Here your Cash Coins, luck with your business!.";
					break;

				case 3:
					mes "[^FFA500Terra Girl^000000]";
					mes "You see, there are three types of Terra Coins.";
					mes "Gold Coin that you can buy or sell for 10,000 Cash Points.";
					mes "Silver Coin for 5000 Cash Points and Bronze Coin for 1000 Cash Points.";
					next;
					mes "[^FFA500Terra Girl^000000]";
					mes "For example, you can buy some Coins and put them on sale at a store.";
					mes "The player that buys, may vendermelas my back and receive the Cash Point original.";
					next;
					mes "[^FFA500Terra Girl^000000]";
					mes "Players have @ GCash command to transfer Cash Points, but this method is safer.";
					mes "I hope you use it, see you!.";
					break;
			}

			close;
	}
	end;

OnLeave:
	changelook 4,@TView;
	changelook 5,@MView;
	changelook 3,@BView;
	end;

OnLeaveSty:
	if( @OnStylist == 1 )
	{ // Escaping from NPC? return to original palettes
		changelook 1, @HairStyle;
		changelook 6, @HairColor;
		changelook 7, @Clothes;
		set @OnStylist, 0;
	}
	end;
}

morocc,168,85,1	duplicate(Terra Girl#1)	Terra Girl#2	864
geffen,130,67,3	duplicate(Terra Girl#1)	Terra Girl#3	864
payon,166,105,5	duplicate(Terra Girl#1)	Terra Girl#4	864
pay_arche,58,147,3	duplicate(Terra Girl#1)	Terra Girl#5	864
alberta,113,69,5	duplicate(Terra Girl#1)	Terra Girl#6	864
izlude,121,97,5	duplicate(Terra Girl#1)	Terra Girl#7	864
aldebaran,133,114,5	duplicate(Terra Girl#1)	Terra Girl#8	864
xmas,141,136,3	duplicate(Terra Girl#1)	Terra Girl#9	864
comodo,218,136,1	duplicate(Terra Girl#1)	Terra Girl#10	864
yuno,167,187,3	duplicate(Terra Girl#1)	Terra Girl#11	864
amatsu,192,99,5	duplicate(Terra Girl#1)	Terra Girl#12	864
gonryun,166,117,3	duplicate(Terra Girl#1)	Terra Girl#13	864
umbala,117,135,5	duplicate(Terra Girl#1)	Terra Girl#14	864
niflheim,212,184,6	duplicate(Terra Girl#1)	Terra Girl#15	864
louyang,231,100,3	duplicate(Terra Girl#1)	Terra Girl#16	864
jawaii,249,139,4	duplicate(Terra Girl#1)	Terra Girl#17	864
ayothaya,194,173,6	duplicate(Terra Girl#1)	Terra Girl#18	864
einbroch,55,203,5	duplicate(Terra Girl#1)	Terra Girl#19	864
lighthalzen,153,85,7	duplicate(Terra Girl#1)	Terra Girl#20	864
einbech,193,127,5	duplicate(Terra Girl#1)	Terra Girl#21	864
hugel,107,150,5	duplicate(Terra Girl#1)	Terra Girl#22	864
rachel,133,117,5	duplicate(Terra Girl#1)	Terra Girl#23	864
veins,210,108,3	duplicate(Terra Girl#1)	Terra Girl#24	864
moscovia,235,194,3	duplicate(Terra Girl#1)	Terra Girl#25	864
mid_camp,202,291,4	duplicate(Terra Girl#1)	Terra Girl#26	864
brasilis,191,223,5	duplicate(Terra Girl#1)	Terra Girl#27	864

manuk,282,208,2	duplicate(Terra Girl#1)	Terra Girl#28	864
splendide,194,177,4	duplicate(Terra Girl#1)	Terra Girl#29	864