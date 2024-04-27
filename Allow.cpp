#include "Allow.h"






/* не забудь удалить глобальные переменные */
#define FONT_SIZE_DISTR     4
#define HIGHT               10
#define FONT_HEIGH          4

#define FRAME_WIDTH 14
#define FRAME_HEIGHT 10

int const count_note = 3;
double coord_line[3];
double coord_notes[3];
double coord_symbol[3];
int count_note1;
char** count_char;


unsigned int size = 0;
double left_top[3], left_bottom[3], right_top[3], right_bottom[3];

void size_string(int count,
    NXOpen::NXString enum_Characteristic,
    NXOpen::NXString enum_Style,
    NXOpen::NXString enum0,
    NXOpen::NXString enum01 )
{
    if (std::atoi(enum_Characteristic.GetLocaleText()) == 1)
    {
        count += 5;
    }
    if (std::atoi(enum0.GetLocaleText()) != 1)
    {
        count += 4;
    }
    if (std::atoi(enum01.GetLocaleText()) != 1)
    {
        count += 4;
    }
    size = count;
}

//Отрисовка (ни чего не создает только визуальное отображение будущего рисунка)
void motion_cb(double* screen_pos,
    UF_UI_motion_cb_data_p_t  motion_cb_data,
    my_motion_data_t* my_data)
{
    UF_OBJ_disp_props_t attrib;

    std::string str = "<&70><+><%AP12><+>S<O><&F><+><&90>";



    std::string top = "<&70>",
        two_top = "<&60>",
        line_vert = "<+>",
        enter = "<&80>",
        bottom = "<&90>";

    UF_DISP_refresh();
    UF_OBJ_ask_display_properties(motion_cb_data->view_tag, &attrib);
    attrib.color = 148;

    int check = 1;
    if (check == 1)
    {
        left_top[0] = screen_pos[0] - size;
        left_top[1] = screen_pos[1] - 5;
        left_top[2] = 0;

        left_bottom[0] = screen_pos[0] - size;
        left_bottom[1] = screen_pos[1] + 5;
        left_bottom[2] = 0;

    }

    int check2 = 1;
    if (check2 == 1)
    {
        right_top[0] = screen_pos[0] + size;
        right_top[1] = screen_pos[1] - 5;
        right_top[2] = 0;

        right_bottom[0] = screen_pos[0] + size;
        right_bottom[1] = screen_pos[1] + 5;
        right_bottom[2] = 0;

    }
    //Левая линия
    UF_DISP_display_temporary_line
    (motion_cb_data->view_tag, UF_DISP_USE_VIEW_TAG, left_top, left_bottom, &attrib);
    //Правая линия
    UF_DISP_display_temporary_line
    (motion_cb_data->view_tag, UF_DISP_USE_VIEW_TAG, right_top, right_bottom, &attrib);
    //Верхняя линия
    UF_DISP_display_temporary_line
    (motion_cb_data->view_tag, UF_DISP_USE_VIEW_TAG, left_top, right_top, &attrib);
    //Нижняя линия
    UF_DISP_display_temporary_line
    (motion_cb_data->view_tag, UF_DISP_USE_VIEW_TAG, left_bottom, right_bottom, &attrib);

}






void create_allow_udo (
    NXOpen::NXString enum_Characteristic,
    NXOpen::NXString enum_Style,
    NXOpen::NXString enum0,
    NXOpen::NXString string_Allow,
    NXOpen::NXString enum01,
    bool toggle_FreeState,
    bool toggle_TangentPlane,
    bool toggle_Projected,
    NXOpen::NXString string_Projected,
    bool toggle_CircleU,
    NXOpen::NXString string_CircleU,
    bool toggle_Statistical,
    bool toggle_CommonArea,
    bool toggle_Max,
    NXOpen::NXString string_Max,
    double* arc_edge_pos)
{
    std::string top = "<&70>", 
        two_top = "<&60>", 
        line_vert = "<+>",
        enter = "<&80>",
        bottom = "<&90>";

    std::string str_Two;


    NXOpen::NXString str_enum_Characteristic = "<%AP12>";
    //NXOpen::NXString str_enum_Style; //<&60><+><&6><+><E><+><&80><&3><+><&90>
    NXOpen::NXString str_enum0;
    NXOpen::NXString str_enum01;
    
    

    /*switch (std::atoi(enum_Characteristic.GetLocaleText()))
    {
    case 1:
        str_enum_Characteristic = "==";
        UF_UI_write_listing_window(((std::string)enum_Characteristic.GetLocaleText() + "\n").c_str());
        break;
    default: break;
    }*/
    
    //enum 
    switch (std::atoi(enum0.GetLocaleText()))
    {
    case 1:
        str_enum0 = "";
        UF_UI_write_listing_window(((std::string)enum0.GetLocaleText() + "\n").c_str());
        break;
    case 2:
        str_enum0 = "<O>";
        UF_UI_write_listing_window(((std::string)enum0.GetLocaleText() + "\n").c_str());
        break;
    case 3:
        str_enum0 = "S<O>";
        UF_UI_write_listing_window(((std::string)enum0.GetLocaleText() + "\n").c_str());
        break;
    case 4:
        str_enum0 = "<#f>";
        UF_UI_write_listing_window(((std::string)enum0.GetLocaleText() + "\n").c_str());
        break;
    default: break;
    }
    
    //
    switch (std::atoi(enum01.GetLocaleText()))
    {
    case 1: 
        str_enum01 = "";
        UF_UI_write_listing_window(((std::string)enum01.GetLocaleText() + "\n").c_str());
        break;
    case 2: 
        str_enum01 = "<E>";
        UF_UI_write_listing_window(((std::string)enum01.GetLocaleText() + "\n").c_str());
        break;
    case 3: 
        str_enum01 = "<M>";
        UF_UI_write_listing_window(((std::string)enum01.GetLocaleText() + "\n").c_str());
        break;
    case 4: 
        str_enum01 = "<S>";
        UF_UI_write_listing_window(((std::string)enum01.GetLocaleText() + "\n").c_str());
        break;
    default: break;
    }

    str_Two =
        (std::string)str_enum0.GetLocaleText()
        + (std::string)string_Allow.GetLocaleText()
        + (std::string)str_enum01.GetLocaleText();


    if (toggle_FreeState == TRUE)
    {
        str_Two += "<&F>";
    }

    if (toggle_TangentPlane == TRUE)
    {
        str_Two += "<&T>";
    }

    if (toggle_Projected == TRUE)
    {
        str_Two += "<P>";
        str_Two += (std::string)string_Projected.GetLocaleText();
    }

    if (toggle_CircleU == TRUE)
    {
        //24CA
        str_Two += "<&U>";
        str_Two += (std::string)string_CircleU.GetLocaleText();
    }

    if (toggle_Statistical == TRUE)
    {
        str_Two += "<&S>";
    }

    if (toggle_CommonArea == TRUE)
    {
        str_Two += "CZ";
    }

    str_Two += line_vert;

    if (toggle_Max == TRUE)
    {
        str_Two += "MAX";
        str_Two += (std::string)string_Max.GetLocaleText();
        str_Two += line_vert;
    }
        



    /*UF_UDOBJ_class_t class_id;
    UF_UDOBJ_create_class("test", "test name", &class_id);

    tag_t udo_tag;
    UF_UDOBJ_create_udo(class_id, &udo_tag);


    if (udo_tag != NULL_TAG)
    {
        //UF_UDOBJ_add_doubles(udo_tag, 3, threeargs);
        //UF_UDOBJ_ask_udo_data(udo_tag, &all_udo_data);
        //UF_UDOBJ_free_udo_data(&all_udo_data);
    }
    UF_CURVE_line_t line_coords;
    line_coords.start_point[0] = 0;
    line_coords.start_point[1] = 0;
    line_coords.start_point[2] = 0;
    line_coords.end_point[0] = 0;
    line_coords.end_point[1] = 500;
    line_coords.end_point[2] = 0;
    tag_t line;
    UF_CURVE_create_line(&line_coords, &line);*/
    //Ⓐ Ⓑ Ⓒ Ⓓ Ⓔ Ⓕ Ⓖ Ⓗ Ⓘ Ⓙ Ⓚ Ⓛ Ⓜ Ⓝ Ⓞ Ⓟ Ⓠ Ⓡ Ⓢ Ⓣ Ⓤ Ⓥ Ⓦ Ⓧ Ⓨ Ⓩ
    //ℂ ℃ ℄ ℅ ℆ ℇ ℈ ℉ ℊ ℋ ℌ ℍ ℎ ℏ ℐ ℑ ℒ ℓ ℔ ℕ ℗ ℘  ℭ ℮ ℯ ℰ ℱ Ⅎ ℳ ℴ ⅓ ⅔ ⅕ ⅖ ⅗ ⅘ ⅙ ⅚
    //
    //char c;
    //int ascii = 251;
    //UF_TEXT_set_text_mode(UF_TEXT_ALL_UTF8);
/*Условие максимума материала <M> $o
Условие минимума материала <E> Нет
Независимо от размера элемента <S> $q
Выступающее поле допуска <P> $p
Статистический допуск <&S> Нет
Касательная плоскость <&T> Нет
Свободное состояние <&F> Нет*/
    //NXOpen::NXString str = u8"<LⓁ>";
    //char *text_string[4] = { const_cast<char*>(str.getUTF8Text())};
    //char *text_string[4] = { const_cast<char*>("<&T>")};
    //std::vector<NXOpen::NXString> text3(1);
    //text3[0] = NXOpen::NXString("<&70><+><!SYM=\320\237\321\200\320\276\321\204\320\270\320\273\321\214 \321\200\320\265\320\273\321\214\321\201\320\276\320\262\321\213\320\271_1><+><&90>", NXOpen::NXString::UTF8);
    //<%symbol>    <!SYM=2Line_1>
    //str_enum0 + string_Allow + str_enum01;

    

   

    UF_UI_write_listing_window((str_Two + "\n").c_str());


    std::string str_Result = top 
        + line_vert 
        + (std::string)str_enum_Characteristic.GetLocaleText() 
        + line_vert 
        + str_Two 
        + bottom;
    UF_UI_write_listing_window((str_Result + "\n").c_str());

    char *text_string[4] = { const_cast<char*>(str_Result.c_str())};
    double      origin_3d[3] = { arc_edge_pos[0], arc_edge_pos[1], arc_edge_pos[2] };
    int         orientation = 0;
    tag_t note_tag;
    UF_DRF_create_note(1, text_string, origin_3d, orientation, &note_tag);
    

    //UF_DISP_add_item_to_display(udo_tag);

    //Добавление линий и символов к стрелке
    //tag_t arr_tag[1];
    //arr_tag[0] = line;
    //UF_DRF_add_assortpart_to_ann(draftingFeatureControlFrameBuilder2->Tag(), 1, arr_tag);

    



    /*

    NXOpen::Session* theSession = NXOpen::Session::GetSession();
    NXOpen::Part* workPart(theSession->Parts()->Work());
    NXOpen::Part* displayPart(theSession->Parts()->Display());
    // ----------------------------------------------
    //   Menu: Вставить->Аннотация->Примечание...
    // ----------------------------------------------
    NXOpen::Session::UndoMarkId markId1;
    markId1 = theSession->SetUndoMark(NXOpen::Session::MarkVisibilityVisible, NXString("\320\235\320\260\321\207\320\260\320\273\320\276", NXString::UTF8));

    NXOpen::Annotations::SimpleDraftingAid* nullNXOpen_Annotations_SimpleDraftingAid(NULL);
    NXOpen::Annotations::DraftingNoteBuilder* draftingNoteBuilder1;
    draftingNoteBuilder1 = workPart->Annotations()->CreateDraftingNoteBuilder(nullNXOpen_Annotations_SimpleDraftingAid);

    draftingNoteBuilder1->Origin()->SetInferRelativeToGeometry(true);

    draftingNoteBuilder1->Origin()->SetInferRelativeToGeometry(true);

    draftingNoteBuilder1->Origin()->SetAnchor(NXOpen::Annotations::OriginBuilder::AlignmentPositionMidCenter);

    std::vector<NXString> text1(1);
    text1[0] = "";
    draftingNoteBuilder1->Text()->TextBlock()->SetText(text1);

    draftingNoteBuilder1->Text()->TextBlock()->SetSymbolPreferences(NXOpen::Annotations::TextWithSymbolsBuilder::SymbolPreferencesTypeUseDefinition);

    draftingNoteBuilder1->SetTextAlignment(NXOpen::Annotations::DraftingNoteBuilder::TextAlignBelowbottomExtToMax);

    theSession->SetUndoMarkName(markId1, NXString("\320\224\320\270\320\260\320\273\320\276\320\263\320\276\320\262\320\276\320\265 \320\276\320\272\320\275\320\276 \320\227\320\260\320\274\320\265\321\207\320\260\320\275\320\270\320\265", NXString::UTF8));

    draftingNoteBuilder1->Origin()->Plane()->SetPlaneMethod(NXOpen::Annotations::PlaneBuilder::PlaneMethodTypeXyPlane);

    draftingNoteBuilder1->Origin()->SetInferRelativeToGeometry(true);

    NXOpen::Annotations::LeaderData* leaderData1;
    leaderData1 = workPart->Annotations()->CreateLeaderData();

    leaderData1->SetArrowhead(NXOpen::Annotations::LeaderData::ArrowheadTypeFilledArrow);

    leaderData1->SetVerticalAttachment(NXOpen::Annotations::LeaderVerticalAttachmentCenter);

    draftingNoteBuilder1->Leader()->Leaders()->Append(leaderData1);

    leaderData1->SetStubSide(NXOpen::Annotations::LeaderSideInferred);

    double symbolscale1;
    symbolscale1 = draftingNoteBuilder1->Text()->TextBlock()->SymbolScale();

    double symbolaspectratio1;
    symbolaspectratio1 = draftingNoteBuilder1->Text()->TextBlock()->SymbolAspectRatio();

    draftingNoteBuilder1->Origin()->SetInferRelativeToGeometry(true);

    draftingNoteBuilder1->Origin()->SetInferRelativeToGeometry(true);

    /*std::vector<NXString> text2(1);
    text2[0] = "";
    draftingNoteBuilder1->Text()->TextBlock()->SetText(text2);

    std::vector<NXString> text3(1);
    text3[0] = "<&70><+><+><&90>";
    draftingNoteBuilder1->Text()->TextBlock()->SetText(text3);

    std::vector<NXString> text4(1);
    text4[0] = "<&70><+><+><&90>";
    draftingNoteBuilder1->Text()->TextBlock()->SetText(text4);*/
/*
    double symbolWidth1;
    double symbolHeight1;
    NXOpen::SymbolFont* symbolFont1;
    symbolFont1 = workPart->Annotations()->LoadSymbolFontFromSbfFile("ALFA", &symbolWidth1, &symbolHeight1);

    std::vector<NXString> text5(1);
    text5[0] = "<&70><+><+><&90>";
    draftingNoteBuilder1->Text()->TextBlock()->SetText(text5);

    std::vector<NXString> text6(1);
    text6[0] = "<&70><+><%ALFA><+><&90>";
    draftingNoteBuilder1->Text()->TextBlock()->SetText(text6);

    draftingNoteBuilder1->Text()->TextBlock()->SetSymbolScale(1.0);

    draftingNoteBuilder1->Text()->TextBlock()->SetSymbolAspectRatio(1.0);

    draftingNoteBuilder1->Text()->TextBlock()->SetSymbolLength(0.0);

    draftingNoteBuilder1->Text()->TextBlock()->SetSymbolHeight(0.0);

    NXOpen::Annotations::Annotation::AssociativeOriginData assocOrigin1;
    assocOrigin1.OriginType = NXOpen::Annotations::AssociativeOriginTypeDrag;
    NXOpen::View* nullNXOpen_View(NULL);
    assocOrigin1.View = nullNXOpen_View;
    assocOrigin1.ViewOfGeometry = nullNXOpen_View;
    NXOpen::Point* nullNXOpen_Point(NULL);
    assocOrigin1.PointOnGeometry = nullNXOpen_Point;
    NXOpen::Annotations::Annotation* nullNXOpen_Annotations_Annotation(NULL);
    assocOrigin1.VertAnnotation = nullNXOpen_Annotations_Annotation;
    assocOrigin1.VertAlignmentPosition = NXOpen::Annotations::AlignmentPositionTopLeft;
    assocOrigin1.HorizAnnotation = nullNXOpen_Annotations_Annotation;
    assocOrigin1.HorizAlignmentPosition = NXOpen::Annotations::AlignmentPositionTopLeft;
    assocOrigin1.AlignedAnnotation = nullNXOpen_Annotations_Annotation;
    assocOrigin1.DimensionLine = 0;
    assocOrigin1.AssociatedView = nullNXOpen_View;
    assocOrigin1.AssociatedPoint = nullNXOpen_Point;
    assocOrigin1.OffsetAnnotation = nullNXOpen_Annotations_Annotation;
    assocOrigin1.OffsetAlignmentPosition = NXOpen::Annotations::AlignmentPositionTopLeft;
    assocOrigin1.XOffsetFactor = 0.0;
    assocOrigin1.YOffsetFactor = 0.0;
    assocOrigin1.StackAlignmentPosition = NXOpen::Annotations::StackAlignmentPositionAbove;
    draftingNoteBuilder1->Origin()->SetAssociativeOrigin(assocOrigin1);

    NXOpen::Point3d point1(95.4930263252639, 696.265995186957, 0.0);
    draftingNoteBuilder1->Origin()->Origin()->SetValue(NULL, nullNXOpen_View, point1);

    draftingNoteBuilder1->Origin()->SetInferRelativeToGeometry(true);

    NXOpen::Session::UndoMarkId markId2;
    markId2 = theSession->SetUndoMark(NXOpen::Session::MarkVisibilityInvisible, NXString("\320\227\320\260\320\274\320\265\321\207\320\260\320\275\320\270\320\265", NXString::UTF8));

    NXOpen::NXObject* nXObject1;
    nXObject1 = draftingNoteBuilder1->Commit();

    theSession->DeleteUndoMark(markId2, NULL);

    theSession->SetUndoMarkName(markId1, NXString("\320\227\320\260\320\274\320\265\321\207\320\260\320\275\320\270\320\265", NXString::UTF8));

    theSession->SetUndoMarkVisibility(markId1, NULL, NXOpen::Session::MarkVisibilityVisible);

    draftingNoteBuilder1->Destroy();

    NXOpen::Session::UndoMarkId markId3;
    markId3 = theSession->SetUndoMark(NXOpen::Session::MarkVisibilityInvisible, "Start");

    NXOpen::Annotations::DraftingNoteBuilder* draftingNoteBuilder2;
    draftingNoteBuilder2 = workPart->Annotations()->CreateDraftingNoteBuilder(nullNXOpen_Annotations_SimpleDraftingAid);

    draftingNoteBuilder2->Origin()->SetInferRelativeToGeometry(true);

    draftingNoteBuilder2->Origin()->SetInferRelativeToGeometry(true);

    draftingNoteBuilder2->Origin()->SetAnchor(NXOpen::Annotations::OriginBuilder::AlignmentPositionMidCenter);

    std::vector<NXString> text7(1);
    text7[0] = "<&70><+><%ALFA><+><&90>";
    draftingNoteBuilder2->Text()->TextBlock()->SetText(text7);

    draftingNoteBuilder2->Text()->TextBlock()->SetSymbolPreferences(NXOpen::Annotations::TextWithSymbolsBuilder::SymbolPreferencesTypeUseDefinition);

    draftingNoteBuilder2->Style()->DimensionStyle()->SetLimitFitDeviation("H");

    draftingNoteBuilder2->Style()->DimensionStyle()->SetLimitFitShaftDeviation("h");

    draftingNoteBuilder2->SetTextAlignment(NXOpen::Annotations::DraftingNoteBuilder::TextAlignBelowbottomExtToMax);

    theSession->SetUndoMarkName(markId3, NXString("\320\224\320\270\320\260\320\273\320\276\320\263\320\276\320\262\320\276\320\265 \320\276\320\272\320\275\320\276 \320\227\320\260\320\274\320\265\321\207\320\260\320\275\320\270\320\265", NXString::UTF8));

    draftingNoteBuilder2->Origin()->Plane()->SetPlaneMethod(NXOpen::Annotations::PlaneBuilder::PlaneMethodTypeXyPlane);

    draftingNoteBuilder2->Origin()->SetInferRelativeToGeometry(true);

    NXOpen::Annotations::LeaderData* leaderData2;
    leaderData2 = workPart->Annotations()->CreateLeaderData();

    leaderData2->SetArrowhead(NXOpen::Annotations::LeaderData::ArrowheadTypeFilledArrow);

    leaderData2->SetVerticalAttachment(NXOpen::Annotations::LeaderVerticalAttachmentCenter);

    draftingNoteBuilder2->Leader()->Leaders()->Append(leaderData2);

    leaderData2->SetStubSide(NXOpen::Annotations::LeaderSideInferred);

    double symbolscale2;
    symbolscale2 = draftingNoteBuilder2->Text()->TextBlock()->SymbolScale();

    double symbolaspectratio2;
    symbolaspectratio2 = draftingNoteBuilder2->Text()->TextBlock()->SymbolAspectRatio();

    draftingNoteBuilder2->Origin()->SetInferRelativeToGeometry(true);

    draftingNoteBuilder2->Origin()->SetInferRelativeToGeometry(true);

    draftingNoteBuilder2->Destroy();

    theSession->UndoToMark(markId3, NULL);

    theSession->DeleteUndoMark(markId3, NULL);

//-------------------------------------------------------------------------------------------------------
    /*NXOpen::Session* theSession = NXOpen::Session::GetSession();
    NXOpen::Part* workPart(theSession->Parts()->Work());
    NXOpen::Part* displayPart(theSession->Parts()->Display());
    // ----------------------------------------------
    //   Menu: Вставить->Аннотация->Примечание...
    // ----------------------------------------------
    NXOpen::Session::UndoMarkId markId1;
    markId1 = theSession->SetUndoMark(NXOpen::Session::MarkVisibilityVisible, NXString("\320\235\320\260\321\207\320\260\320\273\320\276", NXString::UTF8));

    NXOpen::Annotations::SimpleDraftingAid* nullNXOpen_Annotations_SimpleDraftingAid(NULL);
    NXOpen::Annotations::DraftingNoteBuilder* draftingNoteBuilder1;
    draftingNoteBuilder1 = workPart->Annotations()->CreateDraftingNoteBuilder(nullNXOpen_Annotations_SimpleDraftingAid);

    draftingNoteBuilder1->Origin()->SetInferRelativeToGeometry(true);

    draftingNoteBuilder1->Origin()->SetInferRelativeToGeometry(true);

    draftingNoteBuilder1->Origin()->SetAnchor(NXOpen::Annotations::OriginBuilder::AlignmentPositionMidCenter);

    std::vector<NXString> text1(1);
    text1[0] = "<&70><+><+><&90>";
    draftingNoteBuilder1->Text()->TextBlock()->SetText(text1);

    draftingNoteBuilder1->Text()->TextBlock()->SetSymbolPreferences(NXOpen::Annotations::TextWithSymbolsBuilder::SymbolPreferencesTypeUseDefinition);

    draftingNoteBuilder1->SetTextAlignment(NXOpen::Annotations::DraftingNoteBuilder::TextAlignBelowbottomExtToMax);

    theSession->SetUndoMarkName(markId1, NXString("\320\224\320\270\320\260\320\273\320\276\320\263\320\276\320\262\320\276\320\265 \320\276\320\272\320\275\320\276 \320\227\320\260\320\274\320\265\321\207\320\260\320\275\320\270\320\265", NXString::UTF8));

    draftingNoteBuilder1->Origin()->Plane()->SetPlaneMethod(NXOpen::Annotations::PlaneBuilder::PlaneMethodTypeXyPlane);

    draftingNoteBuilder1->Origin()->SetInferRelativeToGeometry(true);

    NXOpen::Annotations::LeaderData* leaderData1;
    leaderData1 = workPart->Annotations()->CreateLeaderData();

    leaderData1->SetArrowhead(NXOpen::Annotations::LeaderData::ArrowheadTypeFilledArrow);

    leaderData1->SetVerticalAttachment(NXOpen::Annotations::LeaderVerticalAttachmentCenter);

    draftingNoteBuilder1->Leader()->Leaders()->Append(leaderData1);

    leaderData1->SetStubSide(NXOpen::Annotations::LeaderSideInferred);

    double symbolscale1;
    symbolscale1 = draftingNoteBuilder1->Text()->TextBlock()->SymbolScale();

    double symbolaspectratio1;
    symbolaspectratio1 = draftingNoteBuilder1->Text()->TextBlock()->SymbolAspectRatio();

    draftingNoteBuilder1->Origin()->SetInferRelativeToGeometry(true);

    draftingNoteBuilder1->Origin()->SetInferRelativeToGeometry(true);

    NXOpen::Annotations::CustomSymbol* nullNXOpen_Annotations_CustomSymbol(NULL);
    NXOpen::Annotations::DraftingCustomSymbolBuilder* draftingCustomSymbolBuilder1;
    draftingCustomSymbolBuilder1 = workPart->Annotations()->CustomSymbols()->CreateDraftingCustomSymbolBuilder(nullNXOpen_Annotations_CustomSymbol);

    draftingCustomSymbolBuilder1->SelectSymbol(NXString("D:\\setting_10\\symbol\\ESKD\\\320\270\320\267 \320\223\320\236\320\241\320\242 2.410-68\\Curve\\CurveRail.sym.prt", NXString::UTF8));

    draftingCustomSymbolBuilder1->SetGeometryPreference(NXOpen::Annotations::BaseCustomSymbolBuilder::GeometryPreferencesUseDefinition);

    draftingCustomSymbolBuilder1->SetAnnotationPreference(NXOpen::Annotations::BaseCustomSymbolBuilder::AnnotationPreferencesUseDefinition);

    NXOpen::NXObject* nXObject1;
    nXObject1 = draftingCustomSymbolBuilder1->Commit();

    draftingCustomSymbolBuilder1->Destroy();

    NXOpen::Annotations::CustomSymbol* customSymbol1(dynamic_cast<NXOpen::Annotations::CustomSymbol*>(nXObject1));
    draftingNoteBuilder1->Text()->TextBlock()->AddSymbol(customSymbol1, NXString("\320\237\321\200\320\276\321\204\320\270\320\273\321\214 \321\200\320\265\320\273\321\214\321\201\320\276\320\262\321\213\320\271_1", NXString::UTF8), 1, 9);

    std::vector<NXString> text2(1);
    text2[0] = "<&70><+><+><&90>";
    draftingNoteBuilder1->Text()->TextBlock()->SetText(text2);

    std::vector<NXString> text3(1);
    text3[0] = NXString("<&70><+><!SYM=\320\237\321\200\320\276\321\204\320\270\320\273\321\214 \321\200\320\265\320\273\321\214\321\201\320\276\320\262\321\213\320\271_1><+><&90>", NXString::UTF8);
    draftingNoteBuilder1->Text()->TextBlock()->SetText(text3);

    NXOpen::Annotations::Annotation::AssociativeOriginData assocOrigin1;
    assocOrigin1.OriginType = NXOpen::Annotations::AssociativeOriginTypeDrag;
    NXOpen::View* nullNXOpen_View(NULL);
    assocOrigin1.View = nullNXOpen_View;
    assocOrigin1.ViewOfGeometry = nullNXOpen_View;
    NXOpen::Point* nullNXOpen_Point(NULL);
    assocOrigin1.PointOnGeometry = nullNXOpen_Point;
    NXOpen::Annotations::Annotation* nullNXOpen_Annotations_Annotation(NULL);
    assocOrigin1.VertAnnotation = nullNXOpen_Annotations_Annotation;
    assocOrigin1.VertAlignmentPosition = NXOpen::Annotations::AlignmentPositionTopLeft;
    assocOrigin1.HorizAnnotation = nullNXOpen_Annotations_Annotation;
    assocOrigin1.HorizAlignmentPosition = NXOpen::Annotations::AlignmentPositionTopLeft;
    assocOrigin1.AlignedAnnotation = nullNXOpen_Annotations_Annotation;
    assocOrigin1.DimensionLine = 0;
    assocOrigin1.AssociatedView = nullNXOpen_View;
    assocOrigin1.AssociatedPoint = nullNXOpen_Point;
    assocOrigin1.OffsetAnnotation = nullNXOpen_Annotations_Annotation;
    assocOrigin1.OffsetAlignmentPosition = NXOpen::Annotations::AlignmentPositionTopLeft;
    assocOrigin1.XOffsetFactor = 0.0;
    assocOrigin1.YOffsetFactor = 0.0;
    assocOrigin1.StackAlignmentPosition = NXOpen::Annotations::StackAlignmentPositionAbove;
    draftingNoteBuilder1->Origin()->SetAssociativeOrigin(assocOrigin1);

    NXOpen::Point3d point1(71.3526858118626, 471.294131357536, 0.0);
    draftingNoteBuilder1->Origin()->Origin()->SetValue(NULL, nullNXOpen_View, point1);

    draftingNoteBuilder1->Origin()->SetInferRelativeToGeometry(true);

    NXOpen::Session::UndoMarkId markId2;
    markId2 = theSession->SetUndoMark(NXOpen::Session::MarkVisibilityInvisible, NXString("\320\227\320\260\320\274\320\265\321\207\320\260\320\275\320\270\320\265", NXString::UTF8));

    NXOpen::NXObject* nXObject2;
    nXObject2 = draftingNoteBuilder1->Commit();

    theSession->DeleteUndoMark(markId2, NULL);

    theSession->SetUndoMarkName(markId1, NXString("\320\227\320\260\320\274\320\265\321\207\320\260\320\275\320\270\320\265", NXString::UTF8));

    theSession->SetUndoMarkVisibility(markId1, NULL, NXOpen::Session::MarkVisibilityVisible);

    draftingNoteBuilder1->Destroy();

    NXOpen::Session::UndoMarkId markId3;
    markId3 = theSession->SetUndoMark(NXOpen::Session::MarkVisibilityInvisible, "Start");

    NXOpen::Annotations::DraftingNoteBuilder* draftingNoteBuilder2;
    draftingNoteBuilder2 = workPart->Annotations()->CreateDraftingNoteBuilder(nullNXOpen_Annotations_SimpleDraftingAid);

    draftingNoteBuilder2->Origin()->SetInferRelativeToGeometry(true);

    draftingNoteBuilder2->Origin()->SetInferRelativeToGeometry(true);

    draftingNoteBuilder2->Origin()->SetAnchor(NXOpen::Annotations::OriginBuilder::AlignmentPositionMidCenter);

    std::vector<NXString> text4(1);
    text4[0] = NXString("<&70><+><!SYM=\320\237\321\200\320\276\321\204\320\270\320\273\321\214 \321\200\320\265\320\273\321\214\321\201\320\276\320\262\321\213\320\271_1><+><&90>", NXString::UTF8);
    draftingNoteBuilder2->Text()->TextBlock()->SetText(text4);

    draftingNoteBuilder2->Text()->TextBlock()->SetSymbolPreferences(NXOpen::Annotations::TextWithSymbolsBuilder::SymbolPreferencesTypeUseDefinition);

    draftingNoteBuilder2->Style()->DimensionStyle()->SetLimitFitDeviation("H");

    draftingNoteBuilder2->Style()->DimensionStyle()->SetLimitFitShaftDeviation("h");

    draftingNoteBuilder2->SetTextAlignment(NXOpen::Annotations::DraftingNoteBuilder::TextAlignBelowbottomExtToMax);

    theSession->SetUndoMarkName(markId3, NXString("\320\224\320\270\320\260\320\273\320\276\320\263\320\276\320\262\320\276\320\265 \320\276\320\272\320\275\320\276 \320\227\320\260\320\274\320\265\321\207\320\260\320\275\320\270\320\265", NXString::UTF8));

    std::vector<NXString> text5(1);
    text5[0] = "";
    draftingNoteBuilder2->Text()->TextBlock()->SetText(text5);

    std::vector<NXString> text6(1);
    text6[0] = "<&70><+><+><&90>";
    draftingNoteBuilder2->Text()->TextBlock()->SetText(text6);

    std::vector<NXString> text7(1);
    text7[0] = "<&70><+><+><&90>";
    draftingNoteBuilder2->Text()->TextBlock()->SetText(text7);

    draftingNoteBuilder2->Origin()->Plane()->SetPlaneMethod(NXOpen::Annotations::PlaneBuilder::PlaneMethodTypeXyPlane);

    draftingNoteBuilder2->Origin()->SetInferRelativeToGeometry(true);

    NXOpen::Annotations::LeaderData* leaderData2;
    leaderData2 = workPart->Annotations()->CreateLeaderData();

    leaderData2->SetArrowhead(NXOpen::Annotations::LeaderData::ArrowheadTypeFilledArrow);

    leaderData2->SetVerticalAttachment(NXOpen::Annotations::LeaderVerticalAttachmentCenter);

    draftingNoteBuilder2->Leader()->Leaders()->Append(leaderData2);

    leaderData2->SetStubSide(NXOpen::Annotations::LeaderSideInferred);

    double symbolscale2;
    symbolscale2 = draftingNoteBuilder2->Text()->TextBlock()->SymbolScale();

    double symbolaspectratio2;
    symbolaspectratio2 = draftingNoteBuilder2->Text()->TextBlock()->SymbolAspectRatio();

    draftingNoteBuilder2->Origin()->SetInferRelativeToGeometry(true);

    draftingNoteBuilder2->Origin()->SetInferRelativeToGeometry(true);

    std::vector<NXString> text8(1);
    text8[0] = "<&70><+><+><&90>";
    draftingNoteBuilder2->Text()->TextBlock()->SetText(text8);

    std::vector<NXString> text9(1);
    text9[0] = "<&70><+><+><&90>";
    draftingNoteBuilder2->Text()->TextBlock()->SetText(text9);

    draftingNoteBuilder2->Destroy();

    theSession->UndoToMark(markId3, NULL);

    theSession->DeleteUndoMark(markId3, NULL);/**/


}

void create_allow()
{
    NXOpen::Session* theSession = NXOpen::Session::GetSession();
    NXOpen::Part* workPart(theSession->Parts()->Work());
    NXOpen::Part* displayPart(theSession->Parts()->Display());
    // ----------------------------------------------
    //   Menu: Вставить->Аннотация->Допуск формы и расположения...
    // ----------------------------------------------
    NXOpen::Session::UndoMarkId markId1;
    markId1 = theSession->SetUndoMark(NXOpen::Session::MarkVisibilityVisible, NXOpen::NXString("\320\235\320\260\321\207\320\260\320\273\320\276", NXOpen::NXString::UTF8));

    NXOpen::Annotations::Gdt* nullNXOpen_Annotations_Gdt(NULL);
    NXOpen::Annotations::DraftingFeatureControlFrameBuilder* draftingFeatureControlFrameBuilder1;
    draftingFeatureControlFrameBuilder1 = workPart->Annotations()->CreateDraftingFeatureControlFrameBuilder(nullNXOpen_Annotations_Gdt);

    draftingFeatureControlFrameBuilder1->Origin()->SetInferRelativeToGeometry(true);

    draftingFeatureControlFrameBuilder1->Origin()->SetInferRelativeToGeometry(true);

    draftingFeatureControlFrameBuilder1->Origin()->SetAnchor(NXOpen::Annotations::OriginBuilder::AlignmentPositionMidCenter);

    draftingFeatureControlFrameBuilder1->SetCharacteristic(NXOpen::Annotations::FeatureControlFrameBuilder::FcfCharacteristicSymmetry);


    /*
    NXOpen::Annotations::StyleBuilder* Style = draftingFeatureControlFrameBuilder1->Style();
    NXOpen::Annotations::SymbolStyleBuilder* SymbolStyle = Style->SymbolStyle();//  NXOpen::Annotations::StyleBuilder::SymbolStyle;
    NXOpen::Annotations::FrameBarStyleBuilder* FrameBarStyle = Style->FrameBarStyle();
    NXOpen::Annotations::FrameBarElementStyleBuilder* TransverseFramesStyle = FrameBarStyle->TransverseFramesStyle();

    TransverseFramesStyle->SetTicColor(200);
    TransverseFramesStyle->SetExtendedTicColor(200);
    TransverseFramesStyle->SetLabelColor(200);
    TransverseFramesStyle->SetExtendedTicFont(20);


    SymbolStyle->SetCenterlineSymbolWidth(NXOpen::Annotations::LineWidth::LineWidthEight);
    SymbolStyle->SetGdtSymbolWidth(NXOpen::Annotations::LineWidth::LineWidthEight);
    SymbolStyle->SetIdSymbolWidth(NXOpen::Annotations::LineWidth::LineWidthEight);
    SymbolStyle->SetIntersectionSymbolWidth(NXOpen::Annotations::LineWidth::LineWidthEight);
    SymbolStyle->SetSurfaceFinishWidth(NXOpen::Annotations::LineWidth::LineWidthEight);
    SymbolStyle->SetUserDefinedSymbolWidth(NXOpen::Annotations::LineWidth::LineWidthEight);
    SymbolStyle->SetWeldSymbolWidth(NXOpen::Annotations::LineWidth::LineWidthEight);


    SymbolStyle->SetGdtSymbolFont(NXOpen::DisplayableObject::ObjectFont::ObjectFontDashed);
    SymbolStyle->SetIdSymbolFont(NXOpen::DisplayableObject::ObjectFont::ObjectFontDashed);
    SymbolStyle->SetIntersectionSymbolFont(NXOpen::DisplayableObject::ObjectFont::ObjectFontDashed);
    SymbolStyle->SetSurfaceFinishFont(NXOpen::DisplayableObject::ObjectFont::ObjectFontDashed);
    SymbolStyle->SetTargetSymbolFont(NXOpen::DisplayableObject::ObjectFont::ObjectFontDashed);
    SymbolStyle->SetTargetSymbolFont(NXOpen::DisplayableObject::ObjectFont::ObjectFontDashed);
    SymbolStyle->SetUserDefinedSymbolFont(NXOpen::DisplayableObject::ObjectFont::ObjectFontDashed);
    SymbolStyle->SetWeldSymbolFont(NXOpen::DisplayableObject::ObjectFont::ObjectFontDashed);
*/


    std::vector<NXOpen::NXString> text1(1);
    text1[0] = "<My Feature Control Frame>";
    draftingFeatureControlFrameBuilder1->Text()->SetText(text1);

    draftingFeatureControlFrameBuilder1->Text()->SetSymbolPreferences(NXOpen::Annotations::TextWithSymbolsBuilder::SymbolPreferencesTypeUseDefinition);

    theSession->SetUndoMarkName(markId1, NXOpen::NXString("\320\224\320\270\320\260\320\273\320\276\320\263\320\276\320\262\320\276\320\265 \320\276\320\272\320\275\320\276 \320\224\320\276\320\277\321\203\321\201\320\272 \321\204\320\276\321\200\320\274\321\213 \320\270 \321\200\320\260\321\201\320\277\320\276\320\273\320\276\320\266\320\265\320\275\320\270\321\217", NXOpen::NXString::UTF8));

    draftingFeatureControlFrameBuilder1->Origin()->Plane()->SetPlaneMethod(NXOpen::Annotations::PlaneBuilder::PlaneMethodTypeXyPlane);

    draftingFeatureControlFrameBuilder1->Origin()->SetInferRelativeToGeometry(true);

    NXOpen::Annotations::LeaderData* leaderData1;
    leaderData1 = workPart->Annotations()->CreateLeaderData();

    leaderData1->SetArrowhead(NXOpen::Annotations::LeaderData::ArrowheadTypeFilledArrow);

    leaderData1->SetVerticalAttachment(NXOpen::Annotations::LeaderVerticalAttachmentCenter);

    draftingFeatureControlFrameBuilder1->Leader()->Leaders()->Append(leaderData1);

    leaderData1->SetStubSide(NXOpen::Annotations::LeaderSideInferred);

    NXOpen::TaggedObject* taggedObject1;
    taggedObject1 = draftingFeatureControlFrameBuilder1->FeatureControlFrameDataList()->FindItem(0);

    NXOpen::Annotations::FeatureControlFrameDataBuilder* featureControlFrameDataBuilder1(dynamic_cast<NXOpen::Annotations::FeatureControlFrameDataBuilder*>(taggedObject1));
    NXOpen::TaggedObject* taggedObject2;
    taggedObject2 = draftingFeatureControlFrameBuilder1->FeatureControlFrameDataList()->FindItem(1);

    NXOpen::Annotations::FeatureControlFrameDataBuilder* featureControlFrameDataBuilder2(dynamic_cast<NXOpen::Annotations::FeatureControlFrameDataBuilder*>(taggedObject2));
    double symbolscale1;
    symbolscale1 = draftingFeatureControlFrameBuilder1->Text()->SymbolScale();

    double symbolaspectratio1;
    symbolaspectratio1 = draftingFeatureControlFrameBuilder1->Text()->SymbolAspectRatio();

    double symbollength1;
    symbollength1 = draftingFeatureControlFrameBuilder1->Text()->SymbolLength();

    double symbolheight1;
    symbolheight1 = draftingFeatureControlFrameBuilder1->Text()->SymbolHeight();

    draftingFeatureControlFrameBuilder1->Text()->SetSymbolLength(0.0);

    draftingFeatureControlFrameBuilder1->Text()->SetSymbolHeight(0.0);

    draftingFeatureControlFrameBuilder1->Origin()->SetInferRelativeToGeometry(true);

    draftingFeatureControlFrameBuilder1->Origin()->SetInferRelativeToGeometry(true);

    NXOpen::Annotations::Annotation::AssociativeOriginData assocOrigin1;
    assocOrigin1.OriginType = NXOpen::Annotations::AssociativeOriginTypeDrag;
    NXOpen::View* nullNXOpen_View(NULL);
    assocOrigin1.View = nullNXOpen_View;
    assocOrigin1.ViewOfGeometry = nullNXOpen_View;
    NXOpen::Point* nullNXOpen_Point(NULL);
    assocOrigin1.PointOnGeometry = nullNXOpen_Point;
    NXOpen::Annotations::Annotation* nullNXOpen_Annotations_Annotation(NULL);
    assocOrigin1.VertAnnotation = nullNXOpen_Annotations_Annotation;
    assocOrigin1.VertAlignmentPosition = NXOpen::Annotations::AlignmentPositionTopLeft;
    assocOrigin1.HorizAnnotation = nullNXOpen_Annotations_Annotation;
    assocOrigin1.HorizAlignmentPosition = NXOpen::Annotations::AlignmentPositionTopLeft;
    assocOrigin1.AlignedAnnotation = nullNXOpen_Annotations_Annotation;
    assocOrigin1.DimensionLine = 0;
    assocOrigin1.AssociatedView = nullNXOpen_View;
    assocOrigin1.AssociatedPoint = nullNXOpen_Point;
    assocOrigin1.OffsetAnnotation = nullNXOpen_Annotations_Annotation;
    assocOrigin1.OffsetAlignmentPosition = NXOpen::Annotations::AlignmentPositionTopLeft;
    assocOrigin1.XOffsetFactor = 0.0;
    assocOrigin1.YOffsetFactor = 0.0;
    assocOrigin1.StackAlignmentPosition = NXOpen::Annotations::StackAlignmentPositionAbove;
    draftingFeatureControlFrameBuilder1->Origin()->SetAssociativeOrigin(assocOrigin1);

    NXOpen::Point3d point1(10, 500, 0.0);
    draftingFeatureControlFrameBuilder1->Origin()->Origin()->SetValue(NULL, nullNXOpen_View, point1);

    draftingFeatureControlFrameBuilder1->Origin()->SetInferRelativeToGeometry(true);

    featureControlFrameDataBuilder1->SetPrimaryDatumExtendedText("");

    featureControlFrameDataBuilder1->SetSecondaryDatumExtendedText("");

    featureControlFrameDataBuilder1->SetTertiaryDatumExtendedText("");

    featureControlFrameDataBuilder2->SetPrimaryDatumExtendedText("");

    featureControlFrameDataBuilder2->SetSecondaryDatumExtendedText("");

    featureControlFrameDataBuilder2->SetTertiaryDatumExtendedText("");

    NXOpen::Session::UndoMarkId markId2;
    markId2 = theSession->SetUndoMark(NXOpen::Session::MarkVisibilityInvisible, NXOpen::NXString("\320\224\320\276\320\277\321\203\321\201\320\272 \321\204\320\276\321\200\320\274\321\213 \320\270 \321\200\320\260\321\201\320\277\320\276\320\273\320\276\320\266\320\265\320\275\320\270\321\217", NXOpen::NXString::UTF8));


    NXOpen::NXObject* nXObject1;
    nXObject1 = draftingFeatureControlFrameBuilder1->Commit();

    theSession->DeleteUndoMark(markId2, NULL);

    theSession->SetUndoMarkName(markId1, NXOpen::NXString("\320\224\320\276\320\277\321\203\321\201\320\272 \321\204\320\276\321\200\320\274\321\213 \320\270 \321\200\320\260\321\201\320\277\320\276\320\273\320\276\320\266\320\265\320\275\320\270\321\217", NXOpen::NXString::UTF8));

    theSession->SetUndoMarkVisibility(markId1, NULL, NXOpen::Session::MarkVisibilityVisible);

    draftingFeatureControlFrameBuilder1->Destroy();

    NXOpen::Session::UndoMarkId markId3;
    markId3 = theSession->SetUndoMark(NXOpen::Session::MarkVisibilityInvisible, "Start");

    NXOpen::Annotations::DraftingFeatureControlFrameBuilder* draftingFeatureControlFrameBuilder2;
    draftingFeatureControlFrameBuilder2 = workPart->Annotations()->CreateDraftingFeatureControlFrameBuilder(nullNXOpen_Annotations_Gdt);

    draftingFeatureControlFrameBuilder2->Origin()->SetInferRelativeToGeometry(true);

    draftingFeatureControlFrameBuilder2->Origin()->SetInferRelativeToGeometry(true);

    draftingFeatureControlFrameBuilder2->Origin()->SetAnchor(NXOpen::Annotations::OriginBuilder::AlignmentPositionMidCenter);

    draftingFeatureControlFrameBuilder2->SetCharacteristic(NXOpen::Annotations::FeatureControlFrameBuilder::FcfCharacteristicCircularity);

    std::vector<NXOpen::NXString> text2(1);
    text2[0] = "<My Feature Control Frame>";
    draftingFeatureControlFrameBuilder2->Text()->SetText(text2);

    draftingFeatureControlFrameBuilder2->Text()->SetSymbolPreferences(NXOpen::Annotations::TextWithSymbolsBuilder::SymbolPreferencesTypeUseDefinition);

    draftingFeatureControlFrameBuilder2->Style()->DimensionStyle()->SetLimitFitDeviation("H");

    draftingFeatureControlFrameBuilder2->Style()->DimensionStyle()->SetLimitFitShaftDeviation("h");

    theSession->SetUndoMarkName(markId3, NXOpen::NXString("\320\224\320\270\320\260\320\273\320\276\320\263\320\276\320\262\320\276\320\265 \320\276\320\272\320\275\320\276 \320\224\320\276\320\277\321\203\321\201\320\272 \321\204\320\276\321\200\320\274\321\213 \320\270 \321\200\320\260\321\201\320\277\320\276\320\273\320\276\320\266\320\265\320\275\320\270\321\217", NXOpen::NXString::UTF8));

    NXOpen::TaggedObject* taggedObject3;
    taggedObject3 = draftingFeatureControlFrameBuilder2->FeatureControlFrameDataList()->FindItem(0);

    NXOpen::Annotations::FeatureControlFrameDataBuilder* featureControlFrameDataBuilder3(dynamic_cast<NXOpen::Annotations::FeatureControlFrameDataBuilder*>(taggedObject3));
    NXOpen::TaggedObject* taggedObject4;
    taggedObject4 = draftingFeatureControlFrameBuilder2->FeatureControlFrameDataList()->FindItem(1);

    NXOpen::Annotations::FeatureControlFrameDataBuilder* featureControlFrameDataBuilder4(dynamic_cast<NXOpen::Annotations::FeatureControlFrameDataBuilder*>(taggedObject4));
    draftingFeatureControlFrameBuilder2->Origin()->Plane()->SetPlaneMethod(NXOpen::Annotations::PlaneBuilder::PlaneMethodTypeXyPlane);

    draftingFeatureControlFrameBuilder2->Origin()->SetInferRelativeToGeometry(true);

    NXOpen::Annotations::LeaderData* leaderData2;
    leaderData2 = workPart->Annotations()->CreateLeaderData();

    leaderData2->SetArrowhead(NXOpen::Annotations::LeaderData::ArrowheadTypeFilledArrow);

    leaderData2->SetVerticalAttachment(NXOpen::Annotations::LeaderVerticalAttachmentCenter);

    draftingFeatureControlFrameBuilder2->Leader()->Leaders()->Append(leaderData2);

    leaderData2->SetStubSide(NXOpen::Annotations::LeaderSideInferred);

    double symbolscale2;
    symbolscale2 = draftingFeatureControlFrameBuilder2->Text()->SymbolScale();

    double symbolaspectratio2;
    symbolaspectratio2 = draftingFeatureControlFrameBuilder2->Text()->SymbolAspectRatio();

    double symbollength2;
    symbollength2 = draftingFeatureControlFrameBuilder2->Text()->SymbolLength();

    double symbolheight2;
    symbolheight2 = draftingFeatureControlFrameBuilder2->Text()->SymbolHeight();

    draftingFeatureControlFrameBuilder2->Text()->SetSymbolLength(0.0);

    draftingFeatureControlFrameBuilder2->Text()->SetSymbolHeight(0.0);

    draftingFeatureControlFrameBuilder2->Origin()->SetInferRelativeToGeometry(true);

    draftingFeatureControlFrameBuilder2->Origin()->SetInferRelativeToGeometry(true);

    draftingFeatureControlFrameBuilder2->Destroy();

    theSession->UndoToMark(markId3, NULL);

    theSession->DeleteUndoMark(markId3, NULL);

}