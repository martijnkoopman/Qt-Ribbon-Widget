/*
 * Copyright (C) Martijn Koopman
 * All Rights Reserved
 *
 * This software is distributed WITHOUT ANY WARRANTY; without even
 * the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE.
 *
 */

#ifndef RIBBONTABWIDGET_H
#define RIBBONTABWIDGET_H

#include <QTabWidget>
#include <QToolButton>

class Ribbon : public QTabWidget
{
  Q_OBJECT
public:
  explicit Ribbon(QWidget *parent = 0);

  /// Add a tab to the ribbon.
  ///
  /// \param[in] tabName Name of the tab
  void addTab(const QString &tabName);

  /// Add a tab to the ribbon.
  ///
  /// \param[in] tabIcon Icon of the tab
  /// \param[in] tabName Name of the tab
  void addTab(const QIcon &tabIcon, const QString &tabName);

  /// Remove a tab from the ribbon.
  ///
  /// \param[in] tabName Name of the tab
  void removeTab(const QString &tabName);

  /// Add a group to the specified tab.
  /// The specified tab is created if it does not exist.
  ///
  /// \param[in] tabName Name of the tab
  /// \param[in] groupName Name of the group
  void addGroup(const QString &tabName, const QString &groupName);

  /// Add a button to the specified group.
  /// The specified group and tab are created if they do not exist.
  ///
  /// \param[in] tabName Name of the tab
  /// \param[in] groupName Name of the group
  /// \param[in] button The button
  void addButton(const QString &tabName, const QString &groupName, QToolButton *button);

  /// Remove a button from the specified group.
  /// Do nothing if the button, group or tab doesn't exist.
  /// The button group and tab are also removed if they become empty due to
  /// the removal of the button.
  ///
  /// \param[in] tabName Name of the tab
  /// \param[in] groupName Name of the group
  /// \param[in] button The button
  void removeButton(const QString &tabName, const QString &groupName, QToolButton *button);
};

#endif // RIBBONTABWIDGET_H
