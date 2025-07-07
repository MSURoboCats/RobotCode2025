# generated from rosidl_generator_py/resource/_idl.py.em
# with input from custom_interfaces:srv/GenerateWorldMap.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_GenerateWorldMap_Request(type):
    """Metaclass of message 'GenerateWorldMap_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('custom_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'custom_interfaces.srv.GenerateWorldMap_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__generate_world_map__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__generate_world_map__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__generate_world_map__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__generate_world_map__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__generate_world_map__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class GenerateWorldMap_Request(metaclass=Metaclass_GenerateWorldMap_Request):
    """Message class 'GenerateWorldMap_Request'."""

    __slots__ = [
    ]

    _fields_and_field_types = {
    }

    SLOT_TYPES = (
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)


# Import statements for member types

import builtins  # noqa: E402, I100

# already imported above
# import rosidl_parser.definition


class Metaclass_GenerateWorldMap_Response(type):
    """Metaclass of message 'GenerateWorldMap_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('custom_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'custom_interfaces.srv.GenerateWorldMap_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__generate_world_map__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__generate_world_map__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__generate_world_map__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__generate_world_map__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__generate_world_map__response

            from custom_interfaces.msg import WorldMap
            if WorldMap.__class__._TYPE_SUPPORT is None:
                WorldMap.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class GenerateWorldMap_Response(metaclass=Metaclass_GenerateWorldMap_Response):
    """Message class 'GenerateWorldMap_Response'."""

    __slots__ = [
        '_out_map',
        '_success',
    ]

    _fields_and_field_types = {
        'out_map': 'custom_interfaces/WorldMap',
        'success': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['custom_interfaces', 'msg'], 'WorldMap'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from custom_interfaces.msg import WorldMap
        self.out_map = kwargs.get('out_map', WorldMap())
        self.success = kwargs.get('success', bool())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.out_map != other.out_map:
            return False
        if self.success != other.success:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def out_map(self):
        """Message field 'out_map'."""
        return self._out_map

    @out_map.setter
    def out_map(self, value):
        if __debug__:
            from custom_interfaces.msg import WorldMap
            assert \
                isinstance(value, WorldMap), \
                "The 'out_map' field must be a sub message of type 'WorldMap'"
        self._out_map = value

    @builtins.property
    def success(self):
        """Message field 'success'."""
        return self._success

    @success.setter
    def success(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'success' field must be of type 'bool'"
        self._success = value


class Metaclass_GenerateWorldMap(type):
    """Metaclass of service 'GenerateWorldMap'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('custom_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'custom_interfaces.srv.GenerateWorldMap')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__generate_world_map

            from custom_interfaces.srv import _generate_world_map
            if _generate_world_map.Metaclass_GenerateWorldMap_Request._TYPE_SUPPORT is None:
                _generate_world_map.Metaclass_GenerateWorldMap_Request.__import_type_support__()
            if _generate_world_map.Metaclass_GenerateWorldMap_Response._TYPE_SUPPORT is None:
                _generate_world_map.Metaclass_GenerateWorldMap_Response.__import_type_support__()


class GenerateWorldMap(metaclass=Metaclass_GenerateWorldMap):
    from custom_interfaces.srv._generate_world_map import GenerateWorldMap_Request as Request
    from custom_interfaces.srv._generate_world_map import GenerateWorldMap_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
