/*
 * Copyright (C) Martijn Koopman
 * All Rights Reserved
 *
 * This software is distributed WITHOUT ANY WARRANTY; without even
 * the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE.
 *
 */

#ifndef RIBBONTABCONTENT_H
#define RIBBONTABCONTENT_H

#include <QWidget>
#include <QToolButton>

namespace Ui {
class RibbonTabContent;
}

class RibbonTabContent : public QWidget
{
  Q_OBJECT

public:
  explicit RibbonTabContent(QWidget *parent = 0);
  virtual ~RibbonTabContent();

  /// Add a group to the tab content.
  ///
  /// \param[in] groupName Name of the group
  void addGroup(const QString &groupName);

  /// Remove a group from the tab content.
  ///
  /// \param[in] groupName Name of the group
  void removeGroup(const QString &groupName);

  /// Get the number of button groups in this tab content.
  ///
  /// \return The number of button groups
  int groupCount() const;

  /// Add a button to the specified group.
  /// The group is created if it does not exist.
  ///
  /// \param[in] groupName Name of the group
  /// \param[in] button The button
  void addButton(const QString &groupName, QToolButton *button);

  /// Remove a button from the specified group.
  /// The group is also removed if it's empty.
  ///
  /// \param[in] groupName Name of the group
  /// \param[in] button The button
  void removeButton(const QString &groupName, QToolButton *button);

private:
  Ui::RibbonTabContent *ui;
};

#endif // RIBBONTABCONTENT_H
