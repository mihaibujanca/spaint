/**
 * spaint: LabelManager.cpp
 */

#ifndef H_SPAINT_LABELMANAGER
#define H_SPAINT_LABELMANAGER

#include <map>
#include <string>

#include <tvgutil/IDAllocator.h>

#include "SpaintVoxel.h"

namespace spaint {

/**
 * \brief An instance of this class can be used to manage the labels that are used for labelling a scene.
 */
class LabelManager
{
  //#################### PRIVATE VARIABLES ####################
private:
  /** The ID allocator used to allocate labels. */
  tvgutil::IDAllocator m_labelAllocator;

  /** A map from label names to labels. */
  std::map<std::string,SpaintVoxel::LabelType> m_labelsByName;

  /** A map from labels to their properties (names and colours). */
  std::map<SpaintVoxel::LabelType,std::pair<std::string,Vector3u> > m_labelProperties;

  /** The maximum number of labels that the manager is allowed to allocate. */
  size_t m_maxLabelCount;

  //#################### CONSTRUCTORS ####################
public:
  /**
   * \brief Constructs a label manager.
   *
   * Note: The maximum number of labels that can be specified is limited by the number of available colours (currently 20).
   *
   * \param maxLabelCount The maximum number of labels that the manager is allowed to allocate.
   */
  explicit LabelManager(size_t maxLabelCount);

  //#################### PUBLIC MEMBER FUNCTIONS ####################
public:
  /**
   * \brief Attempts to add a label with the specified name.
   *
   * A label will only be added if we have not yet reached the maximum label count.
   *
   * \param name  The name of the label we want to add.
   * \return      true, if we successfully added the label, or false otherwise.
   */
  bool add_label(const std::string& name);

  /**
   * \brief Deletes the specified label.
   *
   * \param label               The label to delete.
   * \throws std::runtime_error If the manager does not contain the specified label.
   */
  void delete_label(SpaintVoxel::LabelType label);

  /**
   * \brief Gets the label with the specified name.
   *
   * \param name                The name of the label we want to get.
   * \return                    The label with the specified name.
   * \throws std::runtime_error If the manager does not contain a label with the specified name.
   */
  SpaintVoxel::LabelType get_label(const std::string& name) const;

  /**
   * \brief Gets the colour of the specified label.
   *
   * \param label               The label whose colour we want to get.
   * \return                    The colour of the specified label.
   * \throws std::runtime_error If the manager does not contain the specified label.
   */
  Vector3u get_label_colour(SpaintVoxel::LabelType label) const;

  /**
   * \brief Gets the name of the specified label.
   *
   * \param label               The label whose name we want to get.
   * \return                    The name of the specified label.
   * \throws std::runtime_error If the manager does not contain the specified label.
   */
  std::string get_label_name(SpaintVoxel::LabelType label) const;

  /**
   * \brief Gets whether or not the manager contains the specified label.
   *
   * \param name  The label we want to check.
   * \return      true, if the manager contains the specified label, or false otherwise.
   */
  bool has_label(SpaintVoxel::LabelType label) const;

  /**
   * \brief Gets whether or not the manager contains a label with the specified name.
   *
   * \param name  The name of the label we want to check.
   * \return      true, if the manager contains a label with the specified name, or false otherwise.
   */
  bool has_label(const std::string& name) const;

  /**
   * \brief Gets the number of labels that are currently allocated.
   *
   * \return  The number of labels that are currently allocated.
   */
  size_t label_count() const;

  /**
   * \brief Gets the maximum number of labels that the manager is allowed to allocate.
   *
   * \return  The maximum number of labels that the manager is allowed to allocate.
   */
  size_t max_label_count() const;
};

}

#endif
