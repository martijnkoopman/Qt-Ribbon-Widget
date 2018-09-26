/*
 * Copyright (C) Martijn Koopman
 * All Rights Reserved
 *
 * This software is distributed WITHOUT ANY WARRANTY; without even
 * the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE.
 *
 */

#include "ribbontabcontent.h"
#include "ui_ribbontabcontent.h"
#include "ribbonbuttongroup.h"

RibbonTabContent::RibbonTabContent(QWidget *parent)
  : QWidget(parent)
  , ui(new Ui::RibbonTabContent)
{
  ui->setupUi(this);
}

RibbonTabContent::~RibbonTabContent()
{
  delete ui;
}

void RibbonTabContent::addGroup(const QString &groupName)
{
  RibbonButtonGroup *ribbonButtonGroup = new RibbonButtonGroup;
  ribbonButtonGroup->setTitle(groupName);

  ui->ribbonHorizontalLayout->addWidget(ribbonButtonGroup);
}

void RibbonTabContent::removeGroup(const QString &groupName)
{
  // Find ribbon group
  for (int i = 0; i < ui->ribbonHorizontalLayout->count(); i++)
  {
    RibbonButtonGroup *group = static_cast<RibbonButtonGroup*>(ui->ribbonHorizontalLayout->itemAt(i)->widget());
    if (group->title().toLower() == groupName.toLower())
    {
      ui->ribbonHorizontalLayout->removeWidget(group); /// \todo :( No effect
      delete group;
      break;
    }
  }

  /// \todo  What if the group still contains buttons? Delete manually?
  // Or automaticly deleted by Qt parent() system.
}

int RibbonTabContent::groupCount() const
{
  return ui->ribbonHorizontalLayout->count();
}

void RibbonTabContent::addButton(const QString &groupName, QToolButton *button)
{
  // Find ribbon group
  RibbonButtonGroup *ribbonButtonGroup = nullptr;
  for (int i = 0; i < ui->ribbonHorizontalLayout->count(); i++)
  {
    RibbonButtonGroup *group = static_cast<RibbonButtonGroup*>(ui->ribbonHorizontalLayout->itemAt(i)->widget());
    if (group->title().toLower() == groupName.toLower())
    {
      ribbonButtonGroup = group;
      break;
    }
  }

  if (ribbonButtonGroup != nullptr)
  {
    // Group found
    // Add ribbon button
    ribbonButtonGroup->addButton(button);
  }
  else
  {
    // Group not found
    // Add ribbon group
    addGroup(groupName);

    // Add ribbon button
    addButton(groupName, button);
  }
}

void RibbonTabContent::removeButton(const QString &groupName, QToolButton *button)
{
  // Find ribbon group
  RibbonButtonGroup *ribbonButtonGroup = nullptr;
  for (int i = 0; i < ui->ribbonHorizontalLayout->count(); i++)
  {
    RibbonButtonGroup *group = static_cast<RibbonButtonGroup*>(ui->ribbonHorizontalLayout->itemAt(i)->widget());
    if (group->title().toLower() == groupName.toLower())
    {
      ribbonButtonGroup = group;
      break;
    }
  }

  if (ribbonButtonGroup != nullptr)
  {
    // Group found
    // Remove ribbon button
    ribbonButtonGroup->removeButton(button);

    if (ribbonButtonGroup->buttonCount() == 0)
    {
      // Empty button group
      // Remove button group
      removeGroup(groupName);
    }
  }
}
