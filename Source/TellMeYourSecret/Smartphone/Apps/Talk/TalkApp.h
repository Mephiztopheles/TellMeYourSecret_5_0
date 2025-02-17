﻿#pragma once

#include "TellMeYourSecret/Smartphone/PhoneData.h"
#include "TellMeYourSecret/Smartphone/Apps/AppWidget.h"

#include "TalkApp.generated.h"

class UComboBoxString;
class UButton;
class UChatMessage;
class UEditableTextBox;
class UListView;
class UWidgetSwitcher;

UCLASS(BlueprintType)
class TELLMEYOURSECRET_API UTalkApp : public UAppWidget
{
    GENERATED_BODY()

public:
    virtual int  GetRow() const override { return 2; }
    virtual int  GetColumn() const override { return 1; }
    virtual bool Back_Implementation() override;
    virtual void NativeConstruct() override;
    virtual void NativeOnInitialized() override;
    
    void OpenChat(ECharacterIdentifier Identifier);

    UChatMessage* SendChatMessage(const ECharacterIdentifier Sender, const ECharacterIdentifier Recipient, const FText Message, TArray<FText> Answers);

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta=(BindWidget))
    UWidgetSwitcher* MainFrame;
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta=(BindWidget))
    UListView* ContactList;
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta=(BindWidget))
    UListView* MessageList;
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta=(BindWidget))
    UComboBoxString* ChatComboBox;
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta=(BindWidget))
    UButton* SendButton;

private:
    UPROPERTY()
    UChatMessage* Selected;
    UFUNCTION()
    void OpenChat(UObject* SelectedItem);
    UFUNCTION()
    void Send();
    UFUNCTION()
    void OnNotification(UAppWidget* App);

    void UpdateChatList();
};
