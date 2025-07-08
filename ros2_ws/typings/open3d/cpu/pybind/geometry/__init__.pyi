from __future__ import annotations
import numpy
import open3d.cpu.pybind.camera
import open3d.cpu.pybind.utility
import typing
import typing_extensions
from . import keypoint
__all__ = ['All', 'Average', 'AxisAlignedBoundingBox', 'Color', 'DeformAsRigidAsPossibleEnergy', 'FilterScope', 'Gaussian3', 'Gaussian5', 'Gaussian7', 'Geometry', 'Geometry2D', 'Geometry3D', 'HalfEdge', 'HalfEdgeTriangleMesh', 'Image', 'ImageFilterType', 'KDTreeFlann', 'KDTreeSearchParam', 'KDTreeSearchParamHybrid', 'KDTreeSearchParamKNN', 'KDTreeSearchParamRadius', 'LineSet', 'MeshBase', 'Normal', 'Octree', 'OctreeColorLeafNode', 'OctreeInternalNode', 'OctreeInternalPointNode', 'OctreeLeafNode', 'OctreeNode', 'OctreeNodeInfo', 'OctreePointColorLeafNode', 'OrientedBoundingBox', 'PointCloud', 'Quadric', 'RGBDImage', 'SimplificationContraction', 'Smoothed', 'Sobel3dx', 'Sobel3dy', 'Spokes', 'TetraMesh', 'TriangleMesh', 'Vertex', 'Voxel', 'VoxelGrid', 'get_rotation_matrix_from_axis_angle', 'get_rotation_matrix_from_quaternion', 'get_rotation_matrix_from_xyz', 'get_rotation_matrix_from_xzy', 'get_rotation_matrix_from_yxz', 'get_rotation_matrix_from_yzx', 'get_rotation_matrix_from_zxy', 'get_rotation_matrix_from_zyx', 'keypoint']
class AxisAlignedBoundingBox(Geometry3D):
    """
    Class that defines an axis_aligned box that can be computed from 3D geometries, The axis aligned bounding box uses the coordinate axes for bounding box generation.
    """
    @staticmethod
    def create_from_points(points):
        """
        Creates the bounding box that encloses the set of points.
        
        Args:
            points (open3d.utility.Vector3dVector): A list of points.
        
        Returns:
            open3d.geometry.AxisAlignedBoundingBox
        """
    def __copy__(self) -> AxisAlignedBoundingBox:
        ...
    def __deepcopy__(self, arg0: dict) -> AxisAlignedBoundingBox:
        ...
    def __iadd__(self, arg0: AxisAlignedBoundingBox) -> AxisAlignedBoundingBox:
        ...
    @typing.overload
    def __init__(self) -> None:
        """
        Default constructor
        """
    @typing.overload
    def __init__(self, arg0: AxisAlignedBoundingBox) -> None:
        """
        Copy constructor
        """
    @typing.overload
    def __init__(self, min_bound: numpy.ndarray[numpy.float64[3, 1]], max_bound: numpy.ndarray[numpy.float64[3, 1]]) -> None:
        """
        Create an AxisAlignedBoundingBox from min bounds and max bounds in x, y and z
        """
    def __repr__(self) -> str:
        ...
    def get_box_points(self):
        """
        Returns the eight points that define the bounding box.
        
        Returns:
            open3d.utility.Vector3dVector
        """
    def get_extent(self):
        """
        Get the extent/length of the bounding box in x, y, and z dimension.
        
        Returns:
            numpy.ndarray[numpy.float64[3, 1]]
        """
    def get_half_extent(self):
        """
        Returns the half extent of the bounding box.
        
        Returns:
            numpy.ndarray[numpy.float64[3, 1]]
        """
    def get_max_extent(self):
        """
        Returns the maximum extent, i.e. the maximum of X, Y and Z axis
        
        Returns:
            float
        """
    def get_point_indices_within_bounding_box(self, points):
        """
        Return indices to points that are within the bounding box.
        
        Args:
            points (open3d.utility.Vector3dVector): A list of points.
        
        Returns:
            List[int]
        """
    def get_print_info(self):
        """
        Returns the 3D dimensions of the bounding box in string format.
        
        Returns:
            str
        """
    def volume(self):
        """
        Returns the volume of the bounding box.
        
        Returns:
            float
        """
    @property
    def color(self) -> numpy.ndarray[numpy.float64[3, 1]]:
        """
        ``float64`` array of shape ``(3, )``
        """
    @color.setter
    def color(self, arg0: numpy.ndarray[numpy.float64[3, 1]]) -> None:
        ...
    @property
    def max_bound(self) -> numpy.ndarray[numpy.float64[3, 1]]:
        """
        ``float64`` array of shape ``(3, )``
        """
    @max_bound.setter
    def max_bound(self, arg0: numpy.ndarray[numpy.float64[3, 1]]) -> None:
        ...
    @property
    def min_bound(self) -> numpy.ndarray[numpy.float64[3, 1]]:
        """
        ``float64`` array of shape ``(3, )``
        """
    @min_bound.setter
    def min_bound(self, arg0: numpy.ndarray[numpy.float64[3, 1]]) -> None:
        ...
class DeformAsRigidAsPossibleEnergy:
    """
    Members:
    
      Spokes : is the original energy as formulated in orkine and Alexa, "As-Rigid-As-Possible Surface Modeling", 2007.
    
      Smoothed : adds a rotation smoothing term to the rotations.
    """
    Smoothed: typing.ClassVar[DeformAsRigidAsPossibleEnergy]  # value = <DeformAsRigidAsPossibleEnergy.Smoothed: 1>
    Spokes: typing.ClassVar[DeformAsRigidAsPossibleEnergy]  # value = <DeformAsRigidAsPossibleEnergy.Spokes: 0>
    __members__: typing.ClassVar[dict[str, DeformAsRigidAsPossibleEnergy]]  # value = {'Spokes': <DeformAsRigidAsPossibleEnergy.Spokes: 0>, 'Smoothed': <DeformAsRigidAsPossibleEnergy.Smoothed: 1>}
    def __eq__(self, other: typing.Any) -> bool:
        ...
    def __getstate__(self) -> int:
        ...
    def __hash__(self) -> int:
        ...
    def __index__(self) -> int:
        ...
    def __init__(self, value: int) -> None:
        ...
    def __int__(self) -> int:
        ...
    def __ne__(self, other: typing.Any) -> bool:
        ...
    def __repr__(self) -> str:
        ...
    def __setstate__(self, state: int) -> None:
        ...
    def __str__(self) -> str:
        ...
    @property
    def name(self) -> str:
        ...
    @property
    def value(self) -> int:
        ...
class FilterScope:
    """
    Members:
    
      All : All properties (color, normal, vertex position) are filtered.
    
      Color : Only the color values are filtered.
    
      Normal : Only the normal values are filtered.
    
      Vertex : Only the vertex positions are filtered.
    """
    All: typing.ClassVar[FilterScope]  # value = <FilterScope.All: 0>
    Color: typing.ClassVar[FilterScope]  # value = <FilterScope.Color: 1>
    Normal: typing.ClassVar[FilterScope]  # value = <FilterScope.Normal: 2>
    Vertex: typing.ClassVar[FilterScope]  # value = <FilterScope.Vertex: 3>
    __members__: typing.ClassVar[dict[str, FilterScope]]  # value = {'All': <FilterScope.All: 0>, 'Color': <FilterScope.Color: 1>, 'Normal': <FilterScope.Normal: 2>, 'Vertex': <FilterScope.Vertex: 3>}
    def __eq__(self, other: typing.Any) -> bool:
        ...
    def __getstate__(self) -> int:
        ...
    def __hash__(self) -> int:
        ...
    def __index__(self) -> int:
        ...
    def __init__(self, value: int) -> None:
        ...
    def __int__(self) -> int:
        ...
    def __ne__(self, other: typing.Any) -> bool:
        ...
    def __repr__(self) -> str:
        ...
    def __setstate__(self, state: int) -> None:
        ...
    def __str__(self) -> str:
        ...
    @property
    def name(self) -> str:
        ...
    @property
    def value(self) -> int:
        ...
class Geometry:
    """
    The base geometry class.
    """
    class Type:
        """
        Enum class for Geometry types.
        """
        HalfEdgeTriangleMesh: typing.ClassVar[Geometry.Type]  # value = <Type.HalfEdgeTriangleMesh: 7>
        Image: typing.ClassVar[Geometry.Type]  # value = <Type.Image: 8>
        LineSet: typing.ClassVar[Geometry.Type]  # value = <Type.LineSet: 4>
        PointCloud: typing.ClassVar[Geometry.Type]  # value = <Type.PointCloud: 1>
        RGBDImage: typing.ClassVar[Geometry.Type]  # value = <Type.RGBDImage: 9>
        TetraMesh: typing.ClassVar[Geometry.Type]  # value = <Type.TetraMesh: 10>
        TriangleMesh: typing.ClassVar[Geometry.Type]  # value = <Type.TriangleMesh: 6>
        Unspecified: typing.ClassVar[Geometry.Type]  # value = <Type.Unspecified: 0>
        VoxelGrid: typing.ClassVar[Geometry.Type]  # value = <Type.VoxelGrid: 2>
        __members__: typing.ClassVar[dict[str, Geometry.Type]]  # value = {'Unspecified': <Type.Unspecified: 0>, 'PointCloud': <Type.PointCloud: 1>, 'VoxelGrid': <Type.VoxelGrid: 2>, 'LineSet': <Type.LineSet: 4>, 'TriangleMesh': <Type.TriangleMesh: 6>, 'HalfEdgeTriangleMesh': <Type.HalfEdgeTriangleMesh: 7>, 'Image': <Type.Image: 8>, 'RGBDImage': <Type.RGBDImage: 9>, 'TetraMesh': <Type.TetraMesh: 10>}
        def __eq__(self, other: typing.Any) -> bool:
            ...
        def __ge__(self, other: typing.Any) -> bool:
            ...
        def __getstate__(self) -> int:
            ...
        def __gt__(self, other: typing.Any) -> bool:
            ...
        def __hash__(self) -> int:
            ...
        def __index__(self) -> int:
            ...
        def __init__(self, value: int) -> None:
            ...
        def __int__(self) -> int:
            ...
        def __le__(self, other: typing.Any) -> bool:
            ...
        def __lt__(self, other: typing.Any) -> bool:
            ...
        def __ne__(self, other: typing.Any) -> bool:
            ...
        def __repr__(self) -> str:
            ...
        def __setstate__(self, state: int) -> None:
            ...
        def __str__(self) -> str:
            ...
        @property
        def name(self) -> str:
            ...
        @property
        def value(self) -> int:
            ...
    HalfEdgeTriangleMesh: typing.ClassVar[Geometry.Type]  # value = <Type.HalfEdgeTriangleMesh: 7>
    Image: typing.ClassVar[Geometry.Type]  # value = <Type.Image: 8>
    LineSet: typing.ClassVar[Geometry.Type]  # value = <Type.LineSet: 4>
    PointCloud: typing.ClassVar[Geometry.Type]  # value = <Type.PointCloud: 1>
    RGBDImage: typing.ClassVar[Geometry.Type]  # value = <Type.RGBDImage: 9>
    TetraMesh: typing.ClassVar[Geometry.Type]  # value = <Type.TetraMesh: 10>
    TriangleMesh: typing.ClassVar[Geometry.Type]  # value = <Type.TriangleMesh: 6>
    Unspecified: typing.ClassVar[Geometry.Type]  # value = <Type.Unspecified: 0>
    VoxelGrid: typing.ClassVar[Geometry.Type]  # value = <Type.VoxelGrid: 2>
    def clear(self):
        """
        Clear all elements in the geometry.
        
        Returns:
            open3d.geometry.Geometry
        """
    def dimension(self):
        """
        Returns whether the geometry is 2D or 3D.
        
        Returns:
            int
        """
    def get_geometry_type(self):
        """
        Returns one of registered geometry types.
        
        Returns:
            open3d.geometry.Geometry.GeometryType
        """
    def is_empty(self):
        """
        Returns ``True`` iff the geometry is empty.
        
        Returns:
            bool
        """
class Geometry2D(Geometry):
    """
    The base geometry class for 2D geometries.
    """
    def get_max_bound(self):
        """
        Returns max bounds for geometry coordinates.
        
        Returns:
            numpy.ndarray[numpy.float64[2, 1]]
        """
    def get_min_bound(self):
        """
        Returns min bounds for geometry coordinates.
        
        Returns:
            numpy.ndarray[numpy.float64[2, 1]]
        """
class Geometry3D(Geometry):
    """
    The base geometry class for 3D geometries.
    """
    @staticmethod
    def get_rotation_matrix_from_axis_angle(rotation: numpy.ndarray[numpy.float64[3, 1]]) -> numpy.ndarray[numpy.float64[3, 3]]:
        ...
    @staticmethod
    def get_rotation_matrix_from_quaternion(rotation: numpy.ndarray[numpy.float64[4, 1]]) -> numpy.ndarray[numpy.float64[3, 3]]:
        ...
    @staticmethod
    def get_rotation_matrix_from_xyz(rotation: numpy.ndarray[numpy.float64[3, 1]]) -> numpy.ndarray[numpy.float64[3, 3]]:
        ...
    @staticmethod
    def get_rotation_matrix_from_xzy(rotation: numpy.ndarray[numpy.float64[3, 1]]) -> numpy.ndarray[numpy.float64[3, 3]]:
        ...
    @staticmethod
    def get_rotation_matrix_from_yxz(rotation: numpy.ndarray[numpy.float64[3, 1]]) -> numpy.ndarray[numpy.float64[3, 3]]:
        ...
    @staticmethod
    def get_rotation_matrix_from_yzx(rotation: numpy.ndarray[numpy.float64[3, 1]]) -> numpy.ndarray[numpy.float64[3, 3]]:
        ...
    @staticmethod
    def get_rotation_matrix_from_zxy(rotation: numpy.ndarray[numpy.float64[3, 1]]) -> numpy.ndarray[numpy.float64[3, 3]]:
        ...
    @staticmethod
    def get_rotation_matrix_from_zyx(rotation: numpy.ndarray[numpy.float64[3, 1]]) -> numpy.ndarray[numpy.float64[3, 3]]:
        ...
    @staticmethod
    def rotate(*args, **kwargs):
        """
        rotate(*args, **kwargs)
        Overloaded function.
        
        
        1. rotate(self, R)
            Apply rotation to the geometry coordinates and normals.
        
        Args:
            R (numpy.ndarray[numpy.float64[3, 3]]): The rotation matrix
        
        Returns:
            open3d.geometry.Geometry3D
        
        2. rotate(self, R, center)
            Apply rotation to the geometry coordinates and normals.
        
        Args:
            R (numpy.ndarray[numpy.float64[3, 3]]): The rotation matrix
            center (numpy.ndarray[numpy.float64[3, 1]]): Rotation center used for transformation.
        
        Returns:
            open3d.geometry.Geometry3D
        """
    @staticmethod
    def scale(*args, **kwargs):
        """
        scale(*args, **kwargs)
        Overloaded function.
        
        
        1. scale(self, scale, center)
            Apply scaling to the geometry coordinates.
        
        Args:
            scale (float): The scale parameter that is multiplied to the points/vertices of the geometry.
            center (numpy.ndarray[numpy.float64[3, 1]]): Scale center used for transformation.
        
        Returns:
            open3d.geometry.Geometry3D
        
        2. scale(self, scale, center)
            Apply scaling to the geometry coordinates.
        
        Args:
            scale (float): The scale parameter that is multiplied to the points/vertices of the geometry.
            center (numpy.ndarray[numpy.float64[3, 1]]): Scale center used for transformation.
        
        Returns:
            open3d.geometry.Geometry3D
        """
    def get_axis_aligned_bounding_box(self):
        """
        Returns an axis-aligned bounding box of the geometry.
        
        Returns:
            open3d.geometry.AxisAlignedBoundingBox
        """
    def get_center(self):
        """
        Returns the center of the geometry coordinates.
        
        Returns:
            numpy.ndarray[numpy.float64[3, 1]]
        """
    def get_max_bound(self):
        """
        Returns max bounds for geometry coordinates.
        
        Returns:
            numpy.ndarray[numpy.float64[3, 1]]
        """
    def get_min_bound(self):
        """
        Returns min bounds for geometry coordinates.
        
        Returns:
            numpy.ndarray[numpy.float64[3, 1]]
        """
    def get_minimal_oriented_bounding_box(self, robust: bool = False) -> ...:
        """
        Returns the minimal oriented bounding box for the geometry.
        
        Creates the oriented bounding box with the smallest volume.
        The algorithm makes use of the fact that at least one edge of
        the convex hull must be collinear with an edge of the minimum
        bounding box: for each triangle in the convex hull, calculate
        the minimal axis aligned box in the frame of that triangle.
        at the end, return the box with the smallest volume
        
        Args:
             robust (bool): If set to true uses a more robust method which works in
                  degenerate cases but introduces noise to the points coordinates.
        
        Returns:
             open3d.geometry.OrientedBoundingBox: The oriented bounding box. The
             bounding box is oriented such that its volume is minimized.
        """
    def get_oriented_bounding_box(self, robust: bool = False) -> ...:
        """
        Returns the oriented bounding box for the geometry.
        
        Computes the oriented bounding box based on the PCA of the convex hull.
        The returned bounding box is an approximation to the minimal bounding box.
        
        Args:
             robust (bool): If set to true uses a more robust method which works in 
                  degenerate cases but introduces noise to the points coordinates.
        
        Returns:
             open3d.geometry.OrientedBoundingBox: The oriented bounding box. The
             bounding box is oriented such that the axes are ordered with respect to
             the principal components.
        """
    def transform(self, arg0):
        """
        Apply transformation (4x4 matrix) to the geometry coordinates.
        
        Args:
            arg0 (numpy.ndarray[numpy.float64[4, 4]])
        
        Returns:
            open3d.geometry.Geometry3D
        """
    def translate(self, translation, relative = True):
        """
        Apply translation to the geometry coordinates.
        
        Args:
            translation (numpy.ndarray[numpy.float64[3, 1]]): A 3D vector to transform the geometry
            relative (bool, optional, default=True): If true, the translation vector is directly added to the geometry coordinates. Otherwise, the center is moved to the translation vector.
        
        Returns:
            open3d.geometry.Geometry3D
        """
class HalfEdge:
    """
    HalfEdge class contains vertex, triangle info about a half edge, as well as relations of next and twin half edge.
    """
    def __copy__(self) -> HalfEdge:
        ...
    def __deepcopy__(self, arg0: dict) -> HalfEdge:
        ...
    @typing.overload
    def __init__(self) -> None:
        """
        Default constructor
        """
    @typing.overload
    def __init__(self, arg0: HalfEdge) -> None:
        """
        Copy constructor
        """
    def __repr__(self) -> str:
        ...
    def is_boundary(self) -> bool:
        """
        Returns ``True`` iff the half edge is the boundary (has not twin, i.e. twin index == -1).
        """
    @property
    def next(self) -> int:
        """
        int: Index of the next HalfEdge in the same triangle.
        """
    @next.setter
    def next(self, arg0: int) -> None:
        ...
    @property
    def triangle_index(self) -> int:
        """
        int: Index of the triangle containing this half edge
        """
    @triangle_index.setter
    def triangle_index(self, arg0: int) -> None:
        ...
    @property
    def twin(self) -> int:
        """
        int: Index of the twin HalfEdge
        """
    @twin.setter
    def twin(self, arg0: int) -> None:
        ...
    @property
    def vertex_indices(self) -> numpy.ndarray[numpy.int32[2, 1]]:
        """
        List(int) of length 2: Index of the ordered vertices forming this half edge
        """
    @vertex_indices.setter
    def vertex_indices(self, arg0: numpy.ndarray[numpy.int32[2, 1]]) -> None:
        ...
class HalfEdgeTriangleMesh(MeshBase):
    """
    HalfEdgeTriangleMesh inherits TriangleMesh class with the addition of HalfEdge data structure for each half edge in the mesh as well as related functions.
    """
    @staticmethod
    def create_from_triangle_mesh(mesh):
        """
        Convert HalfEdgeTriangleMesh from TriangleMesh. Throws exception if the input mesh is not manifolds
        
        Args:
            mesh (open3d.geometry.TriangleMesh): The input TriangleMesh
        
        Returns:
            open3d.geometry.HalfEdgeTriangleMesh
        """
    def __copy__(self) -> HalfEdgeTriangleMesh:
        ...
    def __deepcopy__(self, arg0: dict) -> HalfEdgeTriangleMesh:
        ...
    @typing.overload
    def __init__(self) -> None:
        """
        Default constructor
        """
    @typing.overload
    def __init__(self, arg0: HalfEdgeTriangleMesh) -> None:
        """
        Copy constructor
        """
    def __repr__(self) -> str:
        ...
    def boundary_half_edges_from_vertex(self, vertex_index):
        """
        Query manifold boundary half edges from a starting vertex. If query vertex is not on boundary, empty vector will be returned.
        
        Args:
            vertex_index (int)
        
        Returns:
            open3d.utility.IntVector
        """
    def boundary_vertices_from_vertex(self):
        """
        Returns:
            open3d.utility.IntVector
        """
    def get_boundaries(self):
        """
        Returns a vector of boundaries. A boundary is a vector of vertices.
        
        Returns:
            List[open3d.utility.IntVector]
        """
    def has_half_edges(self):
        """
        Returns ``True`` if half-edges have already been computed.
        
        Returns:
            bool
        """
    @property
    def half_edges(self) -> list[HalfEdge]:
        """
        List of HalfEdge in the mesh
        """
    @half_edges.setter
    def half_edges(self, arg0: list[HalfEdge]) -> None:
        ...
    @property
    def ordered_half_edge_from_vertex(self) -> list[open3d.cpu.pybind.utility.IntVector]:
        """
        Counter-clockwise ordered half-edges started from each vertex
        """
    @ordered_half_edge_from_vertex.setter
    def ordered_half_edge_from_vertex(self, arg0: list[open3d.cpu.pybind.utility.IntVector]) -> None:
        ...
    @property
    def triangle_normals(self) -> open3d.cpu.pybind.utility.Vector3dVector:
        """
        ``float64`` array of shape ``(num_triangles, 3)``, use ``numpy.asarray()`` to access data: Triangle normals.
        """
    @triangle_normals.setter
    def triangle_normals(self, arg0: open3d.cpu.pybind.utility.Vector3dVector) -> None:
        ...
    @property
    def triangles(self) -> open3d.cpu.pybind.utility.Vector3iVector:
        """
        ``int`` array of shape ``(num_triangles, 3)``, use ``numpy.asarray()`` to access data: List of triangles denoted by the index of points forming the triangle.
        """
    @triangles.setter
    def triangles(self, arg0: open3d.cpu.pybind.utility.Vector3iVector) -> None:
        ...
class Image(Geometry2D):
    """
    The image class stores image with customizable width, height, num of channels and bytes per channel.
    """
    @staticmethod
    def filter_pyramid(image_pyramid, filter_type):
        """
        Function to filter ImagePyramid
        
        Args:
            image_pyramid (List[open3d.geometry.Image]): The ImagePyramid object
            filter_type (open3d.geometry.ImageFilterType): The filter type to be applied.
        
        Returns:
            List[open3d.geometry.Image]
        """
    def __copy__(self) -> Image:
        ...
    def __deepcopy__(self, arg0: dict) -> Image:
        ...
    @typing.overload
    def __init__(self) -> None:
        """
        Default constructor
        """
    @typing.overload
    def __init__(self, arg0: Image) -> None:
        """
        Copy constructor
        """
    @typing.overload
    def __init__(self, arg0: typing_extensions.Buffer) -> None:
        ...
    def __repr__(self) -> str:
        ...
    def create_pyramid(self, num_of_levels, with_gaussian_filter):
        """
        Function to create ImagePyramid
        
        Args:
            num_of_levels (int)
            with_gaussian_filter (bool): When ``True``, image in the pyramid will first be filtered by a 3x3 Gaussian kernel before downsampling.
        
        Returns:
            List[open3d.geometry.Image]
        """
    def filter(self, filter_type):
        """
        Function to filter Image
        
        Args:
            filter_type (open3d.geometry.ImageFilterType): The filter type to be applied.
        
        Returns:
            open3d.geometry.Image
        """
    def flip_horizontal(self) -> Image:
        """
        Function to flip image horizontally (from left to right)
        """
    def flip_vertical(self) -> Image:
        """
        Function to flip image vertically (upside down)
        """
class ImageFilterType:
    """
    Enum class for Image filter types.
    """
    Gaussian3: typing.ClassVar[ImageFilterType]  # value = <ImageFilterType.Gaussian3: 0>
    Gaussian5: typing.ClassVar[ImageFilterType]  # value = <ImageFilterType.Gaussian5: 1>
    Gaussian7: typing.ClassVar[ImageFilterType]  # value = <ImageFilterType.Gaussian7: 2>
    Sobel3dx: typing.ClassVar[ImageFilterType]  # value = <ImageFilterType.Sobel3dx: 3>
    Sobel3dy: typing.ClassVar[ImageFilterType]  # value = <ImageFilterType.Sobel3dy: 4>
    __members__: typing.ClassVar[dict[str, ImageFilterType]]  # value = {'Gaussian3': <ImageFilterType.Gaussian3: 0>, 'Gaussian5': <ImageFilterType.Gaussian5: 1>, 'Gaussian7': <ImageFilterType.Gaussian7: 2>, 'Sobel3dx': <ImageFilterType.Sobel3dx: 3>, 'Sobel3dy': <ImageFilterType.Sobel3dy: 4>}
    def __eq__(self, other: typing.Any) -> bool:
        ...
    def __getstate__(self) -> int:
        ...
    def __hash__(self) -> int:
        ...
    def __index__(self) -> int:
        ...
    def __init__(self, value: int) -> None:
        ...
    def __int__(self) -> int:
        ...
    def __ne__(self, other: typing.Any) -> bool:
        ...
    def __repr__(self) -> str:
        ...
    def __setstate__(self, state: int) -> None:
        ...
    def __str__(self) -> str:
        ...
    @property
    def name(self) -> str:
        ...
    @property
    def value(self) -> int:
        ...
class KDTreeFlann:
    """
    KDTree with FLANN for nearest neighbor search.
    """
    @typing.overload
    def __init__(self) -> None:
        ...
    @typing.overload
    def __init__(self, data: numpy.ndarray[numpy.float64[m, n]]) -> None:
        ...
    @typing.overload
    def __init__(self, geometry: Geometry) -> None:
        ...
    @typing.overload
    def __init__(self, feature: ...) -> None:
        ...
    def search_hybrid_vector_3d(self, query, radius, max_nn):
        """
        Args:
            query (numpy.ndarray[numpy.float64[3, 1]]): The input query point.
            radius (float): Search radius.
            max_nn (int): At maximum, ``max_nn`` neighbors will be searched.
        
        Returns:
            Tuple[int, open3d.utility.IntVector, open3d.utility.DoubleVector]
        """
    def search_hybrid_vector_xd(self, query, radius, max_nn):
        """
        Args:
            query (numpy.ndarray[numpy.float64[m, 1]]): The input query point.
            radius (float): Search radius.
            max_nn (int): At maximum, ``max_nn`` neighbors will be searched.
        
        Returns:
            Tuple[int, open3d.utility.IntVector, open3d.utility.DoubleVector]
        """
    def search_knn_vector_3d(self, query, knn):
        """
        Args:
            query (numpy.ndarray[numpy.float64[3, 1]]): The input query point.
            knn (int): ``knn`` neighbors will be searched.
        
        Returns:
            Tuple[int, open3d.utility.IntVector, open3d.utility.DoubleVector]
        """
    def search_knn_vector_xd(self, query, knn):
        """
        Args:
            query (numpy.ndarray[numpy.float64[m, 1]]): The input query point.
            knn (int): ``knn`` neighbors will be searched.
        
        Returns:
            Tuple[int, open3d.utility.IntVector, open3d.utility.DoubleVector]
        """
    def search_radius_vector_3d(self, query, radius):
        """
        Args:
            query (numpy.ndarray[numpy.float64[3, 1]]): The input query point.
            radius (float): Search radius.
        
        Returns:
            Tuple[int, open3d.utility.IntVector, open3d.utility.DoubleVector]
        """
    def search_radius_vector_xd(self, query, radius):
        """
        Args:
            query (numpy.ndarray[numpy.float64[m, 1]]): The input query point.
            radius (float): Search radius.
        
        Returns:
            Tuple[int, open3d.utility.IntVector, open3d.utility.DoubleVector]
        """
    def search_vector_3d(self, query, search_param):
        """
        Args:
            query (numpy.ndarray[numpy.float64[3, 1]]): The input query point.
            search_param (open3d.geometry.KDTreeSearchParam)
        
        Returns:
            Tuple[int, open3d.utility.IntVector, open3d.utility.DoubleVector]
        """
    def search_vector_xd(self, query, search_param):
        """
        Args:
            query (numpy.ndarray[numpy.float64[m, 1]]): The input query point.
            search_param (open3d.geometry.KDTreeSearchParam)
        
        Returns:
            Tuple[int, open3d.utility.IntVector, open3d.utility.DoubleVector]
        """
    def set_feature(self, feature):
        """
        Sets the data for the KDTree from the feature data.
        
        Args:
            feature (open3d.pipelines.registration.Feature): Feature data.
        
        Returns:
            bool
        """
    def set_geometry(self, geometry):
        """
        Sets the data for the KDTree from geometry.
        
        Args:
            geometry (open3d.geometry.Geometry)
        
        Returns:
            bool
        """
    def set_matrix_data(self, data):
        """
        Sets the data for the KDTree from a matrix.
        
        Args:
            data (numpy.ndarray[numpy.float64[m, n]]): Matrix data.
        
        Returns:
            bool
        """
class KDTreeSearchParam:
    """
    Base class for KDTree search parameters.
    """
    class Type:
        """
        Enum class for Geometry types.
        """
        HybridSearch: typing.ClassVar[KDTreeSearchParam.Type]  # value = <Type.HybridSearch: 2>
        KNNSearch: typing.ClassVar[KDTreeSearchParam.Type]  # value = <Type.KNNSearch: 0>
        RadiusSearch: typing.ClassVar[KDTreeSearchParam.Type]  # value = <Type.RadiusSearch: 1>
        __members__: typing.ClassVar[dict[str, KDTreeSearchParam.Type]]  # value = {'KNNSearch': <Type.KNNSearch: 0>, 'RadiusSearch': <Type.RadiusSearch: 1>, 'HybridSearch': <Type.HybridSearch: 2>}
        def __eq__(self, other: typing.Any) -> bool:
            ...
        def __ge__(self, other: typing.Any) -> bool:
            ...
        def __getstate__(self) -> int:
            ...
        def __gt__(self, other: typing.Any) -> bool:
            ...
        def __hash__(self) -> int:
            ...
        def __index__(self) -> int:
            ...
        def __init__(self, value: int) -> None:
            ...
        def __int__(self) -> int:
            ...
        def __le__(self, other: typing.Any) -> bool:
            ...
        def __lt__(self, other: typing.Any) -> bool:
            ...
        def __ne__(self, other: typing.Any) -> bool:
            ...
        def __repr__(self) -> str:
            ...
        def __setstate__(self, state: int) -> None:
            ...
        def __str__(self) -> str:
            ...
        @property
        def name(self) -> str:
            ...
        @property
        def value(self) -> int:
            ...
    HybridSearch: typing.ClassVar[KDTreeSearchParam.Type]  # value = <Type.HybridSearch: 2>
    KNNSearch: typing.ClassVar[KDTreeSearchParam.Type]  # value = <Type.KNNSearch: 0>
    RadiusSearch: typing.ClassVar[KDTreeSearchParam.Type]  # value = <Type.RadiusSearch: 1>
    def get_search_type(self):
        """
        Get the search type (KNN, Radius, Hybrid) for the search parameter.
        
        Returns:
            open3d.geometry.KDTreeSearchParam.SearchType
        """
class KDTreeSearchParamHybrid(KDTreeSearchParam):
    """
    KDTree search parameters for hybrid KNN and radius search.
    """
    def __init__(self, radius: float, max_nn: int) -> None:
        ...
    def __repr__(self) -> str:
        ...
    @property
    def max_nn(self) -> int:
        """
        At maximum, ``max_nn`` neighbors will be searched.
        """
    @max_nn.setter
    def max_nn(self, arg0: int) -> None:
        ...
    @property
    def radius(self) -> float:
        """
        Search radius.
        """
    @radius.setter
    def radius(self, arg0: float) -> None:
        ...
class KDTreeSearchParamKNN(KDTreeSearchParam):
    """
    KDTree search parameters for pure KNN search.
    """
    def __init__(self, knn: int = 30) -> None:
        ...
    def __repr__(self) -> str:
        ...
    @property
    def knn(self) -> int:
        """
        Number of the neighbors that will be searched.
        """
    @knn.setter
    def knn(self, arg0: int) -> None:
        ...
class KDTreeSearchParamRadius(KDTreeSearchParam):
    """
    KDTree search parameters for pure radius search.
    """
    def __init__(self, radius: float) -> None:
        ...
    def __repr__(self) -> str:
        ...
    @property
    def radius(self) -> float:
        """
        Search radius.
        """
    @radius.setter
    def radius(self, arg0: float) -> None:
        ...
class LineSet(Geometry3D):
    """
    LineSet define a sets of lines in 3D. A typical application is to display the point cloud correspondence pairs.
    """
    @staticmethod
    @typing.overload
    def create_camera_visualization(view_width_px: int, view_height_px: int, intrinsic: numpy.ndarray[numpy.float64[3, 3]], extrinsic: numpy.ndarray[numpy.float64[4, 4]], scale: float = 1.0) -> LineSet:
        """
        Factory function to create a LineSet from intrinsic and extrinsic camera matrices
        """
    @staticmethod
    @typing.overload
    def create_camera_visualization(intrinsic: open3d.cpu.pybind.camera.PinholeCameraIntrinsic, extrinsic: numpy.ndarray[numpy.float64[4, 4]], scale: float = 1.0) -> LineSet:
        """
        Factory function to create a LineSet from intrinsic and extrinsic camera matrices
        """
    @staticmethod
    def create_from_axis_aligned_bounding_box(box):
        """
        Factory function to create a LineSet from an AxisAlignedBoundingBox.
        
        Args:
            box (open3d.geometry.AxisAlignedBoundingBox): The input bounding box.
        
        Returns:
            open3d.geometry.LineSet
        """
    @staticmethod
    def create_from_oriented_bounding_box(box):
        """
        Factory function to create a LineSet from an OrientedBoundingBox.
        
        Args:
            box (open3d.geometry.OrientedBoundingBox): The input bounding box.
        
        Returns:
            open3d.geometry.LineSet
        """
    @staticmethod
    def create_from_point_cloud_correspondences(cloud0, cloud1, correspondences):
        """
        Factory function to create a LineSet from two pointclouds and a correspondence set.
        
        Args:
            cloud0 (open3d.geometry.PointCloud): First point cloud.
            cloud1 (open3d.geometry.PointCloud): Second point cloud.
            correspondences (List[Tuple[int, int]]): Set of correspondences.
        
        Returns:
            open3d.geometry.LineSet
        """
    @staticmethod
    def create_from_tetra_mesh(mesh):
        """
        Factory function to create a LineSet from edges of a tetra mesh.
        
        Args:
            mesh (open3d.geometry.TetraMesh): The input tetra mesh.
        
        Returns:
            open3d.geometry.LineSet
        """
    @staticmethod
    def create_from_triangle_mesh(mesh):
        """
        Factory function to create a LineSet from edges of a triangle mesh.
        
        Args:
            mesh (open3d.geometry.TriangleMesh): The input triangle mesh.
        
        Returns:
            open3d.geometry.LineSet
        """
    def __add__(self, arg0: LineSet) -> LineSet:
        ...
    def __copy__(self) -> LineSet:
        ...
    def __deepcopy__(self, arg0: dict) -> LineSet:
        ...
    def __iadd__(self, arg0: LineSet) -> LineSet:
        ...
    @typing.overload
    def __init__(self) -> None:
        """
        Default constructor
        """
    @typing.overload
    def __init__(self, arg0: LineSet) -> None:
        """
        Copy constructor
        """
    @typing.overload
    def __init__(self, points: open3d.cpu.pybind.utility.Vector3dVector, lines: open3d.cpu.pybind.utility.Vector2iVector) -> None:
        """
        Create a LineSet from given points and line indices
        """
    def __repr__(self) -> str:
        ...
    def get_line_coordinate(self, line_index):
        """
        Args:
            line_index (int): Index of the line.
        
        Returns:
            Tuple[numpy.ndarray[numpy.float64[3, 1]], numpy.ndarray[numpy.float64[3, 1]]]
        """
    def has_colors(self):
        """
        Returns ``True`` if the object's lines contain colors.
        
        Returns:
            bool
        """
    def has_lines(self):
        """
        Returns ``True`` if the object contains lines.
        
        Returns:
            bool
        """
    def has_points(self):
        """
        Returns ``True`` if the object contains points.
        
        Returns:
            bool
        """
    def paint_uniform_color(self, color):
        """
        Assigns each line in the line set the same color.
        
        Args:
            color (numpy.ndarray[numpy.float64[3, 1]]): Color for the LineSet.
        
        Returns:
            open3d.geometry.LineSet
        """
    @property
    def colors(self) -> open3d.cpu.pybind.utility.Vector3dVector:
        """
        ``float64`` array of shape ``(num_lines, 3)``, range ``[0, 1]`` , use ``numpy.asarray()`` to access data: RGB colors of lines.
        """
    @colors.setter
    def colors(self, arg0: open3d.cpu.pybind.utility.Vector3dVector) -> None:
        ...
    @property
    def lines(self) -> open3d.cpu.pybind.utility.Vector2iVector:
        """
        ``int`` array of shape ``(num_lines, 2)``, use ``numpy.asarray()`` to access data: Lines denoted by the index of points forming the line.
        """
    @lines.setter
    def lines(self, arg0: open3d.cpu.pybind.utility.Vector2iVector) -> None:
        ...
    @property
    def points(self) -> open3d.cpu.pybind.utility.Vector3dVector:
        """
        ``float64`` array of shape ``(num_points, 3)``, use ``numpy.asarray()`` to access data: Points coordinates.
        """
    @points.setter
    def points(self, arg0: open3d.cpu.pybind.utility.Vector3dVector) -> None:
        ...
class MeshBase(Geometry3D):
    """
    MeshBase class. Triangle mesh contains vertices. Optionally, the mesh may also contain vertex normals and vertex colors.
    """
    def __add__(self, arg0: MeshBase) -> MeshBase:
        ...
    def __copy__(self) -> MeshBase:
        ...
    def __deepcopy__(self, arg0: dict) -> MeshBase:
        ...
    def __iadd__(self, arg0: MeshBase) -> MeshBase:
        ...
    @typing.overload
    def __init__(self) -> None:
        """
        Default constructor
        """
    @typing.overload
    def __init__(self, arg0: MeshBase) -> None:
        """
        Copy constructor
        """
    def __repr__(self) -> str:
        ...
    def compute_convex_hull(self):
        """
        Computes the convex hull of the triangle mesh.
        
        Returns:
            Tuple[open3d.geometry.TriangleMesh, List[int]]
        """
    def has_vertex_colors(self):
        """
        Returns ``True`` if the mesh contains vertex colors.
        
        Returns:
            bool
        """
    def has_vertex_normals(self):
        """
        Returns ``True`` if the mesh contains vertex normals.
        
        Returns:
            bool
        """
    def has_vertices(self):
        """
        Returns ``True`` if the mesh contains vertices.
        
        Returns:
            bool
        """
    def normalize_normals(self):
        """
        Normalize vertex normals to length 1.
        
        Returns:
            open3d.geometry.MeshBase
        """
    def paint_uniform_color(self, color):
        """
        Assigns each vertex in the MeshBase the same color.
        
        Args:
            color (numpy.ndarray[numpy.float64[3, 1]]): RGB colors of vertices.
        
        Returns:
            open3d.geometry.MeshBase
        """
    @property
    def vertex_colors(self) -> open3d.cpu.pybind.utility.Vector3dVector:
        """
        ``float64`` array of shape ``(num_vertices, 3)``, range ``[0, 1]`` , use ``numpy.asarray()`` to access data: RGB colors of vertices.
        """
    @vertex_colors.setter
    def vertex_colors(self, arg0: open3d.cpu.pybind.utility.Vector3dVector) -> None:
        ...
    @property
    def vertex_normals(self) -> open3d.cpu.pybind.utility.Vector3dVector:
        """
        ``float64`` array of shape ``(num_vertices, 3)``, use ``numpy.asarray()`` to access data: Vertex normals.
        """
    @vertex_normals.setter
    def vertex_normals(self, arg0: open3d.cpu.pybind.utility.Vector3dVector) -> None:
        ...
    @property
    def vertices(self) -> open3d.cpu.pybind.utility.Vector3dVector:
        """
        ``float64`` array of shape ``(num_vertices, 3)``, use ``numpy.asarray()`` to access data: Vertex coordinates.
        """
    @vertices.setter
    def vertices(self, arg0: open3d.cpu.pybind.utility.Vector3dVector) -> None:
        ...
class Octree(Geometry3D):
    """
    Octree datastructure.
    """
    @staticmethod
    def __init__(*args, **kwargs):
        """
        __init__(*args, **kwargs)
        Overloaded function.
        
        
        1. __init__(self)
            Default constructor
        
        2. __init__(self, arg0)
            Copy constructor
        
        Args:
            arg0 (open3d.geometry.Octree)
        
        3. __init__(self, max_depth)
        
        Args:
            max_depth (int)
        
        4. __init__(self, max_depth, origin, size)
        
        Args:
            max_depth (int)
            origin (numpy.ndarray[numpy.float64[3, 1]])
            size (float)
        """
    @staticmethod
    def is_point_in_bound(point, origin, size):
        """
        Return true if point within bound, that is, origin<= point < origin + size
        
        Args:
            point (numpy.ndarray[numpy.float64[3, 1]]): Coordinates of the point.
            origin (numpy.ndarray[numpy.float64[3, 1]]): Origin coordinates.
            size (float): Size of the Octree.
        
        Returns:
            bool
        """
    def __copy__(self) -> Octree:
        ...
    def __deepcopy__(self, arg0: dict) -> Octree:
        ...
    def __repr__(self) -> str:
        ...
    def convert_from_point_cloud(self, point_cloud, size_expand = 0.01):
        """
        Convert octree from point cloud.
        
        Args:
            point_cloud (open3d.geometry.PointCloud): Input point cloud.
            size_expand (float, optional, default=0.01): A small expansion size such that the octree is slightly bigger than the original point cloud bounds to accommodate all points.
        
        Returns:
            None
        """
    def create_from_voxel_grid(self):
        """
        Returns:
            None
        """
    def insert_point(self, point, f_init, f_update, fi_init = None, fi_update = None):
        """
        Insert a point to the octree.
        
        Args:
            point (numpy.ndarray[numpy.float64[3, 1]]): Coordinates of the point.
            f_init (Callable[[], open3d.geometry.OctreeLeafNode])
            f_update (Callable[[open3d.geometry.OctreeLeafNode], None])
            fi_init (Callable[[], open3d.geometry.OctreeInternalNode], optional, default=None)
            fi_update (Callable[[open3d.geometry.OctreeInternalNode], None], optional, default=None)
        
        Returns:
            None
        """
    def locate_leaf_node(self, point):
        """
        Returns leaf OctreeNode and OctreeNodeInfo where the querypoint should reside.
        
        Args:
            point (numpy.ndarray[numpy.float64[3, 1]]): Coordinates of the point.
        
        Returns:
            Tuple[open3d.geometry.OctreeLeafNode, open3d.geometry.OctreeNodeInfo]
        """
    def to_voxel_grid(self):
        """
        Convert to VoxelGrid.
        
        Returns:
            open3d.geometry.VoxelGrid
        """
    def traverse(self, f: typing.Callable[[OctreeNode, OctreeNodeInfo], bool]) -> None:
        """
        DFS traversal of the octree from the root, with a callback function f being called for each node.
        """
    @property
    def max_depth(self) -> int:
        """
        int: Maximum depth of the octree. The depth is defined as the distance from the deepest leaf node to root. A tree with only the root node has depth 0.
        """
    @max_depth.setter
    def max_depth(self, arg0: int) -> None:
        ...
    @property
    def origin(self) -> numpy.ndarray[numpy.float64[3, 1]]:
        """
        (3, 1) float numpy array: Global min bound (include). A point is within bound iff origin <= point < origin + size.
        """
    @origin.setter
    def origin(self, arg0: numpy.ndarray[numpy.float64[3, 1]]) -> None:
        ...
    @property
    def root_node(self) -> OctreeNode:
        """
        OctreeNode: The root octree node.
        """
    @root_node.setter
    def root_node(self, arg0: OctreeNode) -> None:
        ...
    @property
    def size(self) -> float:
        """
        float: Outer bounding box edge size for the whole octree. A point is within bound iff origin <= point < origin + size.
        """
    @size.setter
    def size(self, arg0: float) -> None:
        ...
class OctreeColorLeafNode(OctreeLeafNode):
    """
    OctreeColorLeafNode class is an OctreeLeafNode containing color.
    """
    @staticmethod
    def get_init_function() -> typing.Callable[[], OctreeLeafNode]:
        """
        Get lambda function for initializing OctreeLeafNode. When the init function is called, an empty OctreeColorLeafNode is created.
        """
    @staticmethod
    def get_update_function(color: numpy.ndarray[numpy.float64[3, 1]]) -> typing.Callable[[OctreeLeafNode], None]:
        """
        Get lambda function for updating OctreeLeafNode. When called, the update function updates the corresponding node with the input color.
        """
    def __copy__(self) -> OctreeColorLeafNode:
        ...
    def __deepcopy__(self, arg0: dict) -> OctreeColorLeafNode:
        ...
    @typing.overload
    def __init__(self) -> None:
        """
        Default constructor
        """
    @typing.overload
    def __init__(self, arg0: OctreeColorLeafNode) -> None:
        """
        Copy constructor
        """
    def __repr__(self) -> str:
        ...
    @property
    def color(self) -> numpy.ndarray[numpy.float64[3, 1]]:
        """
        (3, 1) float numpy array: Color of the node.
        """
    @color.setter
    def color(self, arg0: numpy.ndarray[numpy.float64[3, 1]]) -> None:
        ...
class OctreeInternalNode(OctreeNode):
    """
    OctreeInternalNode class, containing OctreeNode children.
    """
    @staticmethod
    def __init__(*args, **kwargs):
        """
        __init__(*args, **kwargs)
        Overloaded function.
        
        
        1. __init__(self)
            Default constructor
        
        2. __init__(self, arg0)
            Copy constructor
        
        Args:
            arg0 (open3d.geometry.OctreeInternalNode)
        """
    @staticmethod
    def get_init_function() -> typing.Callable[[], OctreeInternalNode]:
        """
        Get lambda function for initializing OctreeInternalNode. When the init function is called, an empty OctreeInternalNode is created.
        """
    @staticmethod
    def get_update_function() -> typing.Callable[[OctreeInternalNode], None]:
        """
        Get lambda function for updating OctreeInternalNode. This update function does nothing.
        """
    def __copy__(self) -> OctreeInternalNode:
        ...
    def __deepcopy__(self, arg0: dict) -> OctreeInternalNode:
        ...
    def __repr__(self) -> str:
        ...
    @property
    def children(self) -> list[OctreeNode]:
        """
        List of children Nodes.
        """
    @children.setter
    def children(self, arg0: list[OctreeNode]) -> None:
        ...
class OctreeInternalPointNode(OctreeInternalNode):
    """
    OctreeInternalPointNode class is an OctreeInternalNode with a list of point indices (from point cloud) belonging to children of this node.
    """
    @staticmethod
    def __init__(*args, **kwargs):
        """
        __init__(*args, **kwargs)
        Overloaded function.
        
        
        1. __init__(self)
            Default constructor
        
        2. __init__(self, arg0)
            Copy constructor
        
        Args:
            arg0 (open3d.geometry.OctreeInternalPointNode)
        """
    @staticmethod
    def get_init_function() -> typing.Callable[[], OctreeInternalNode]:
        """
        Get lambda function for initializing OctreeInternalPointNode. When the init function is called, an empty OctreeInternalPointNode is created.
        """
    @staticmethod
    def get_update_function(arg0: int) -> typing.Callable[[OctreeInternalNode], None]:
        """
        Get lambda function for updating OctreeInternalPointNode. When called, the update function adds the input point index to the corresponding node's list of indices of children points.
        """
    def __copy__(self) -> OctreeInternalPointNode:
        ...
    def __deepcopy__(self, arg0: dict) -> OctreeInternalPointNode:
        ...
    def __repr__(self) -> str:
        ...
    @property
    def children(self) -> list[OctreeNode]:
        """
        List of children Nodes.
        """
    @children.setter
    def children(self, arg0: list[OctreeNode]) -> None:
        ...
    @property
    def indices(self) -> list[int]:
        """
        List of point cloud point indices contained in children nodes.
        """
    @indices.setter
    def indices(self, arg0: list[int]) -> None:
        ...
class OctreeLeafNode(OctreeNode):
    """
    OctreeLeafNode base class.
    """
    __hash__: typing.ClassVar[None] = None
    def __eq__(self, other: OctreeLeafNode) -> bool:
        """
        Check equality of OctreeLeafNode.
        """
    def __repr__(self) -> str:
        ...
    def clone(self) -> OctreeLeafNode:
        """
        Clone this OctreeLeafNode.
        """
class OctreeNode:
    """
    The base class for octree node.
    """
    def __repr__(self) -> str:
        ...
class OctreeNodeInfo:
    """
    OctreeNode's information. OctreeNodeInfo is computed on the fly, not stored with the Node.
    """
    def __init__(self, origin, size, depth, child_index):
        """
        Args:
            origin (numpy.ndarray[numpy.float64[3, 1]])
            size (float)
            depth (int)
            child_index (int)
        """
    def __repr__(self) -> str:
        ...
    @property
    def child_index(self) -> int:
        """
        int: Node's child index of itself. For non-root nodes, child_index is 0~7; root node's child_index is -1.
        """
    @child_index.setter
    def child_index(self, arg0: int) -> None:
        ...
    @property
    def depth(self) -> int:
        """
        int: Depth of the node to the root. The root is of depth 0.
        """
    @depth.setter
    def depth(self, arg0: int) -> None:
        ...
    @property
    def origin(self) -> numpy.ndarray[numpy.float64[3, 1]]:
        """
        (3, 1) float numpy array: Origin coordinate of the node.
        """
    @origin.setter
    def origin(self, arg0: numpy.ndarray[numpy.float64[3, 1]]) -> None:
        ...
    @property
    def size(self) -> float:
        """
        float: Size of the node.
        """
    @size.setter
    def size(self, arg0: float) -> None:
        ...
class OctreePointColorLeafNode(OctreeLeafNode):
    """
    OctreePointColorLeafNode class is an OctreeLeafNode containing color.
    """
    @staticmethod
    def get_init_function() -> typing.Callable[[], OctreeLeafNode]:
        """
        Get lambda function for initializing OctreeLeafNode. When the init function is called, an empty OctreePointColorLeafNode is created.
        """
    @staticmethod
    def get_update_function(idx: int, color: numpy.ndarray[numpy.float64[3, 1]]) -> typing.Callable[[OctreeLeafNode], None]:
        """
        Get lambda function for updating OctreeLeafNode. When called, the update function updates the corresponding node with the new point index and the input color.
        """
    def __copy__(self) -> OctreePointColorLeafNode:
        ...
    def __deepcopy__(self, arg0: dict) -> OctreePointColorLeafNode:
        ...
    @typing.overload
    def __init__(self) -> None:
        """
        Default constructor
        """
    @typing.overload
    def __init__(self, arg0: OctreePointColorLeafNode) -> None:
        """
        Copy constructor
        """
    def __repr__(self) -> str:
        ...
    @property
    def color(self) -> numpy.ndarray[numpy.float64[3, 1]]:
        """
        (3, 1) float numpy array: Color of the node.
        """
    @color.setter
    def color(self, arg0: numpy.ndarray[numpy.float64[3, 1]]) -> None:
        ...
    @property
    def indices(self) -> list[int]:
        """
        List of point cloud point indices contained in this leaf node.
        """
    @indices.setter
    def indices(self, arg0: list[int]) -> None:
        ...
class OrientedBoundingBox(Geometry3D):
    """
    Class that defines an oriented box that can be computed from 3D geometries.
    """
    @staticmethod
    def create_from_axis_aligned_bounding_box(aabox):
        """
        Returns an oriented bounding box from the AxisAlignedBoundingBox.
        
        Args:
            aabox (open3d.geometry.AxisAlignedBoundingBox): AxisAlignedBoundingBox object from which OrientedBoundingBox is created.
        
        Returns:
            open3d.geometry.OrientedBoundingBox
        """
    @staticmethod
    def create_from_points(points: open3d.cpu.pybind.utility.Vector3dVector, robust: bool = False) -> OrientedBoundingBox:
        """
        Creates the oriented bounding box that encloses the set of points.
        
        Computes the oriented bounding box based on the PCA of the convex hull.
        The returned bounding box is an approximation to the minimal bounding box.
        
        Args:
             points (open3d.utility.Vector3dVector): Input points.
             robust (bool): If set to true uses a more robust method which works in 
                  degenerate cases but introduces noise to the points coordinates.
        
        Returns:
             open3d.geometry.OrientedBoundingBox: The oriented bounding box. The
             bounding box is oriented such that the axes are ordered with respect to
             the principal components.
        """
    def __copy__(self) -> OrientedBoundingBox:
        ...
    def __deepcopy__(self, arg0: dict) -> OrientedBoundingBox:
        ...
    @typing.overload
    def __init__(self) -> None:
        """
        Default constructor
        """
    @typing.overload
    def __init__(self, arg0: OrientedBoundingBox) -> None:
        """
        Copy constructor
        """
    @typing.overload
    def __init__(self, center: numpy.ndarray[numpy.float64[3, 1]], R: numpy.ndarray[numpy.float64[3, 3]], extent: numpy.ndarray[numpy.float64[3, 1]]) -> None:
        """
        Create OrientedBoudingBox from center, rotation R and extent in x, y and z direction
        """
    def __repr__(self) -> str:
        ...
    def get_box_points(self):
        """
        Returns the eight points that define the bounding box.
        
        Returns:
            open3d.utility.Vector3dVector
        """
    def get_point_indices_within_bounding_box(self, points):
        """
        Return indices to points that are within the bounding box.
        
        Args:
            points (open3d.utility.Vector3dVector): A list of points.
        
        Returns:
            List[int]
        """
    def volume(self):
        """
        Returns the volume of the bounding box.
        
        Returns:
            float
        """
    @property
    def R(self) -> numpy.ndarray[numpy.float64[3, 3]]:
        """
        ``float64`` array of shape ``(3,3 )``
        """
    @R.setter
    def R(self, arg0: numpy.ndarray[numpy.float64[3, 3]]) -> None:
        ...
    @property
    def center(self) -> numpy.ndarray[numpy.float64[3, 1]]:
        """
        ``float64`` array of shape ``(3, )``
        """
    @center.setter
    def center(self, arg0: numpy.ndarray[numpy.float64[3, 1]]) -> None:
        ...
    @property
    def color(self) -> numpy.ndarray[numpy.float64[3, 1]]:
        """
        ``float64`` array of shape ``(3, )``
        """
    @color.setter
    def color(self, arg0: numpy.ndarray[numpy.float64[3, 1]]) -> None:
        ...
    @property
    def extent(self) -> numpy.ndarray[numpy.float64[3, 1]]:
        """
        ``float64`` array of shape ``(3, )``
        """
    @extent.setter
    def extent(self, arg0: numpy.ndarray[numpy.float64[3, 1]]) -> None:
        ...
class PointCloud(Geometry3D):
    """
    PointCloud class. A point cloud consists of point coordinates, and optionally point colors and point normals.
    """
    @staticmethod
    def create_from_depth_image(depth, intrinsic, extrinsic = ..., depth_scale = 1000.0, depth_trunc = 1000.0, stride = 1, project_valid_depth_only = True):
        """
        Factory function to create a pointcloud from a depth image and a
        camera. Given depth value d at (u, v) image coordinate, the corresponding 3d point is:
        
            - z = d / depth_scale
            - x = (u - cx) * z / fx
            - y = (v - cy) * z / fy
        
        Args:
            depth (open3d.geometry.Image): The input depth image can be either a float image, or a uint16_t image.
            intrinsic (open3d.camera.PinholeCameraIntrinsic): Intrinsic parameters of the camera.
            extrinsic (numpy.ndarray[numpy.float64[4, 4]], optional) Default value:
        
                array([[1., 0., 0., 0.],
                [0., 1., 0., 0.],
                [0., 0., 1., 0.],
                [0., 0., 0., 1.]])
            depth_scale (float, optional, default=1000.0): The depth is scaled by 1 / depth_scale.
            depth_trunc (float, optional, default=1000.0): Truncated at depth_trunc distance.
            stride (int, optional, default=1): Sampling factor to support coarse point cloud extraction.
            project_valid_depth_only (bool, optional, default=True)
        
        Returns:
            open3d.geometry.PointCloud
        """
    @staticmethod
    def create_from_rgbd_image(image, intrinsic, extrinsic = ..., project_valid_depth_only = True):
        """
        Factory function to create a pointcloud from an RGB-D image and a camera. Given depth value d at (u, v) image coordinate, the corresponding 3d point is:
        
            - z = d / depth_scale
            - x = (u - cx) * z / fx
            - y = (v - cy) * z / fy
        
        Args:
            image (open3d.geometry.RGBDImage): The input image.
            intrinsic (open3d.camera.PinholeCameraIntrinsic): Intrinsic parameters of the camera.
            extrinsic (numpy.ndarray[numpy.float64[4, 4]], optional) Default value:
        
                array([[1., 0., 0., 0.],
                [0., 1., 0., 0.],
                [0., 0., 1., 0.],
                [0., 0., 0., 1.]])
            project_valid_depth_only (bool, optional, default=True)
        
        Returns:
            open3d.geometry.PointCloud
        """
    @staticmethod
    def crop(*args, **kwargs):
        """
        crop(*args, **kwargs)
        Overloaded function.
        
        
        1. crop(self, bounding_box, invert=False)
            Function to crop input pointcloud into output pointcloud
        
        Args:
            bounding_box (open3d.geometry.AxisAlignedBoundingBox): AxisAlignedBoundingBox to crop points
            invert (bool, optional, default=False): optional boolean to invert cropping
        
        Returns:
            open3d.geometry.PointCloud
        
        2. crop(self, bounding_box, invert=False)
            Function to crop input pointcloud into output pointcloud
        
        Args:
            bounding_box (open3d.geometry.OrientedBoundingBox): AxisAlignedBoundingBox to crop points
            invert (bool, optional, default=False): optional boolean to invert cropping
        
        Returns:
            open3d.geometry.PointCloud
        """
    @staticmethod
    def detect_planar_patches(*args, **kwargs):
        """
        Detects planar patches in the point cloud using a robust statistics-based approach.
        
        Returns:
             A list of detected planar patches, represented as
             OrientedBoundingBox objects, with the third column (z) of R indicating
             the planar patch normal vector. The extent in the z direction is
             non-zero so that the OrientedBoundingBox contains the points that
             contribute to the plane detection.
        
        Args:
            normal_variance_threshold_deg (float, optional, default=60)
            coplanarity_deg (float, optional, default=75)
            outlier_ratio (float, optional, default=0.75): Maximum allowable ratio of outliers associated to a plane.
            min_plane_edge_length (float, optional, default=0.0): Minimum edge length of plane's long edge before being rejected.
            min_num_points (int, optional, default=0): Minimum number of points allowable for fitting planes.
            search_param (open3d.geometry.KDTreeSearchParam, optional, default=KDTreeSearchParamKNN with knn = 30): The KDTree search parameters for neighborhood search.
        
        Returns:
            List[open3d.geometry.OrientedBoundingBox]
        """
    @staticmethod
    def estimate_covariances(*args, **kwargs):
        """
        Function to compute the covariance matrix for each point in the point cloud
        
        Args:
            search_param (open3d.geometry.KDTreeSearchParam, optional, default=KDTreeSearchParamKNN with knn = 30): The KDTree search parameters for neighborhood search.
        
        Returns:
            None
        """
    @staticmethod
    def estimate_normals(*args, **kwargs):
        """
        Function to compute the normals of a point cloud. Normals are oriented with respect to the input point cloud if normals exist
        
        Args:
            search_param (open3d.geometry.KDTreeSearchParam, optional, default=KDTreeSearchParamKNN with knn = 30): The KDTree search parameters for neighborhood search.
            fast_normal_computation (bool, optional, default=True): If true, the normal estimation uses a non-iterative method to extract the eigenvector from the covariance matrix. This is faster, but is not as numerical stable.
        
        Returns:
            None
        """
    @staticmethod
    def estimate_point_covariances(*args, **kwargs):
        """
        Static function to compute the covariance matrix for each point in the given point cloud, doesn't change the input
        
        Args:
            input (open3d.geometry.PointCloud): The input point cloud.
            search_param (open3d.geometry.KDTreeSearchParam, optional, default=KDTreeSearchParamKNN with knn = 30): The KDTree search parameters for neighborhood search.
        
        Returns:
            open3d.utility.Matrix3dVector
        """
    def __add__(self, arg0: PointCloud) -> PointCloud:
        ...
    def __copy__(self) -> PointCloud:
        ...
    def __deepcopy__(self, arg0: dict) -> PointCloud:
        ...
    def __iadd__(self, arg0: PointCloud) -> PointCloud:
        ...
    @typing.overload
    def __init__(self) -> None:
        """
        Default constructor
        """
    @typing.overload
    def __init__(self, arg0: PointCloud) -> None:
        """
        Copy constructor
        """
    @typing.overload
    def __init__(self, points: open3d.cpu.pybind.utility.Vector3dVector) -> None:
        """
        Create a PointCloud from points
        """
    def __repr__(self) -> str:
        ...
    def cluster_dbscan(self, eps, min_points, print_progress = False):
        """
        Cluster PointCloud using the DBSCAN algorithm  Ester et al., 'A Density-Based Algorithm for Discovering Clusters in Large Spatial Databases with Noise', 1996. Returns a list of point labels, -1 indicates noise according to the algorithm.
        
        Args:
            eps (float): Density parameter that is used to find neighbouring points.
            min_points (int): Minimum number of points to form a cluster.
            print_progress (bool, optional, default=False): If true the progress is visualized in the console.
        
        Returns:
            open3d.utility.IntVector
        """
    def compute_convex_hull(self, joggle_inputs: bool = False) -> tuple[..., list[int]]:
        """
        Computes the convex hull of the point cloud.
        
        Args:
             joggle_inputs (bool): If True allows the algorithm to add random noise to
                  the points to work around degenerate inputs. This adds the 'QJ'
                  option to the qhull command.
        
        Returns:
             tuple(open3d.geometry.TriangleMesh, list): The triangle mesh of the convex
             hull and the list of point indices that are part of the convex hull.
        """
    def compute_mahalanobis_distance(self):
        """
        Function to compute the Mahalanobis distance for points in a point cloud. See: https://en.wikipedia.org/wiki/Mahalanobis_distance.
        
        Returns:
            open3d.utility.DoubleVector
        """
    def compute_mean_and_covariance(self):
        """
        Function to compute the mean and covariance matrix of a point cloud.
        
        Returns:
            Tuple[numpy.ndarray[numpy.float64[3, 1]], numpy.ndarray[numpy.float64[3, 3]]]
        """
    def compute_nearest_neighbor_distance(self):
        """
        Function to compute the distance from a point to its nearest neighbor in the point cloud
        
        Returns:
            open3d.utility.DoubleVector
        """
    def compute_point_cloud_distance(self, target):
        """
        For each point in the source point cloud, compute the distance to the target point cloud.
        
        Args:
            target (open3d.geometry.PointCloud): The target point cloud.
        
        Returns:
            open3d.utility.DoubleVector
        """
    def farthest_point_down_sample(self, num_samples: int) -> PointCloud:
        """
        Downsamples input pointcloud into output pointcloud with a set of points has farthest distance. The sample is performed by selecting the farthest point from previous selected points iteratively.
        """
    def has_colors(self):
        """
        Returns ``True`` if the point cloud contains point colors.
        
        Returns:
            bool
        """
    def has_covariances(self) -> bool:
        """
        Returns ``True`` if the point cloud contains covariances.
        """
    def has_normals(self):
        """
        Returns ``True`` if the point cloud contains point normals.
        
        Returns:
            bool
        """
    def has_points(self):
        """
        Returns ``True`` if the point cloud contains points.
        
        Returns:
            bool
        """
    def hidden_point_removal(self, camera_location, radius):
        """
        Removes hidden points from a point cloud and returns a mesh of the remaining points. Based on Katz et al. 'Direct Visibility of Point Sets', 2007. Additional information about the choice of radius for noisy point clouds can be found in Mehra et. al. 'Visibility of Noisy Point Cloud Data', 2010.
        
        Args:
            camera_location (numpy.ndarray[numpy.float64[3, 1]]): All points not visible from that location will be removed
            radius (float): The radius of the sperical projection
        
        Returns:
            Tuple[open3d.geometry.TriangleMesh, List[int]]
        """
    def normalize_normals(self):
        """
        Normalize point normals to length 1.
        
        Returns:
            open3d.geometry.PointCloud
        """
    def orient_normals_consistent_tangent_plane(self, k, lambda = 0.0, cos_alpha_tol = 1.0):
        """
        Function to orient the normals with respect to consistent tangent planes
        
        Args:
            k (int): Number of k nearest neighbors used in constructing the Riemannian graph used to propagate normal orientation.
            lambda (float, optional, default=0.0)
            cos_alpha_tol (float, optional, default=1.0)
        
        Returns:
            None
        """
    def orient_normals_to_align_with_direction(self, orientation_reference = ...):
        """
        Function to orient the normals of a point cloud
        
        Args:
            orientation_reference (numpy.ndarray[numpy.float64[3, 1]], optional, default=array([0., 0., 1.])): Normals are oriented with respect to orientation_reference.
        
        Returns:
            None
        """
    def orient_normals_towards_camera_location(self, camera_location = ...):
        """
        Function to orient the normals of a point cloud
        
        Args:
            camera_location (numpy.ndarray[numpy.float64[3, 1]], optional, default=array([0., 0., 0.])): Normals are oriented with towards the camera_location.
        
        Returns:
            None
        """
    def paint_uniform_color(self, color):
        """
        Assigns each point in the PointCloud the same color.
        
        Args:
            color (numpy.ndarray[numpy.float64[3, 1]]): RGB color for the PointCloud.
        
        Returns:
            open3d.geometry.PointCloud
        """
    def random_down_sample(self, sampling_ratio):
        """
        Function to downsample input pointcloud into output pointcloud randomly. The sample is generated by randomly sampling the indexes from the point cloud.
        
        Args:
            sampling_ratio (float): Sampling ratio, the ratio of number of selected points to total number of points[0-1]
        
        Returns:
            open3d.geometry.PointCloud
        """
    def remove_duplicated_points(self):
        """
        Removes duplicated points, i.e., points that have identical coordinates. It also removes the corresponding attributes associated with the non-finite point such as normals, covariances and color entries. It doesn't re-computes these attributes after removing duplicated points.
        
        Returns:
            open3d.geometry.PointCloud
        """
    def remove_non_finite_points(self, remove_nan = True, remove_infinite = True):
        """
        Removes all points from the point cloud that have a nan entry, or infinite entries. It also removes the corresponding attributes associated with the non-finite point such as normals, covariances and color entries. It doesn't re-computes these attributes after removing non-finite points.
        
        Args:
            remove_nan (bool, optional, default=True): Remove NaN values from the PointCloud
            remove_infinite (bool, optional, default=True): Remove infinite values from the PointCloud
        
        Returns:
            open3d.geometry.PointCloud
        """
    def remove_radius_outlier(self, nb_points, radius, print_progress = False):
        """
        Removes points that have neighbors less than nb_points in a sphere of a given radius
        
        Args:
            nb_points (int): Number of points within the radius.
            radius (float): Radius of the sphere.
            print_progress (bool, optional, default=False): Set to True to print progress bar.
        
        Returns:
            Tuple[open3d.geometry.PointCloud, List[int]]
        """
    def remove_statistical_outlier(self, nb_neighbors, std_ratio, print_progress = False):
        """
        Removes points that are further away from their neighbors in average.
        
        Args:
            nb_neighbors (int): Number of neighbors around the target point.
            std_ratio (float): Standard deviation ratio.
            print_progress (bool, optional, default=False): Set to True to print progress bar.
        
        Returns:
            Tuple[open3d.geometry.PointCloud, List[int]]
        """
    def segment_plane(self, distance_threshold, ransac_n, num_iterations, probability = 0.99999999):
        """
        Segments a plane in the point cloud using the RANSAC algorithm.
        
        Args:
            distance_threshold (float): Max distance a point can be from the plane model, and still be considered an inlier.
            ransac_n (int): Number of initial points to be considered inliers in each iteration.
            num_iterations (int): Number of iterations.
            probability (float, optional, default=0.99999999): Expected probability of finding the optimal plane.
        
        Returns:
            Tuple[numpy.ndarray[numpy.float64[4, 1]], List[int]]
        """
    def select_by_index(self, indices, invert = False):
        """
        Function to select points from input pointcloud into output pointcloud.
        
        Args:
            indices (List[int]): Indices of points to be selected.
            invert (bool, optional, default=False): Set to ``True`` to invert the selection of indices.
        
        Returns:
            open3d.geometry.PointCloud
        """
    def uniform_down_sample(self, every_k_points):
        """
        Function to downsample input pointcloud into output pointcloud uniformly. The sample is performed in the order of the points with the 0-th point always chosen, not at random.
        
        Args:
            every_k_points (int): Sample rate, the selected point indices are [0, k, 2k, ...]
        
        Returns:
            open3d.geometry.PointCloud
        """
    def voxel_down_sample(self, voxel_size):
        """
        Function to downsample input pointcloud into output pointcloud with a voxel. Normals and colors are averaged if they exist.
        
        Args:
            voxel_size (float): Voxel size to downsample into.
        
        Returns:
            open3d.geometry.PointCloud
        """
    def voxel_down_sample_and_trace(self, voxel_size, min_bound, max_bound, approximate_class = False):
        """
        Function to downsample using PointCloud.VoxelDownSample. Also records point cloud index before downsampling
        
        Args:
            voxel_size (float): Voxel size to downsample into.
            min_bound (numpy.ndarray[numpy.float64[3, 1]]): Minimum coordinate of voxel boundaries
            max_bound (numpy.ndarray[numpy.float64[3, 1]]): Maximum coordinate of voxel boundaries
            approximate_class (bool, optional, default=False)
        
        Returns:
            Tuple[open3d.geometry.PointCloud, numpy.ndarray[numpy.int32[m, n]], List[open3d.utility.IntVector]]
        """
    @property
    def colors(self) -> open3d.cpu.pybind.utility.Vector3dVector:
        """
        ``float64`` array of shape ``(num_points, 3)``, range ``[0, 1]`` , use ``numpy.asarray()`` to access data: RGB colors of points.
        """
    @colors.setter
    def colors(self, arg0: open3d.cpu.pybind.utility.Vector3dVector) -> None:
        ...
    @property
    def covariances(self) -> open3d.cpu.pybind.utility.Matrix3dVector:
        """
        ``float64`` array of shape ``(num_points, 3, 3)``, use ``numpy.asarray()`` to access data: Points covariances.
        """
    @covariances.setter
    def covariances(self, arg0: open3d.cpu.pybind.utility.Matrix3dVector) -> None:
        ...
    @property
    def normals(self) -> open3d.cpu.pybind.utility.Vector3dVector:
        """
        ``float64`` array of shape ``(num_points, 3)``, use ``numpy.asarray()`` to access data: Points normals.
        """
    @normals.setter
    def normals(self, arg0: open3d.cpu.pybind.utility.Vector3dVector) -> None:
        ...
    @property
    def points(self) -> open3d.cpu.pybind.utility.Vector3dVector:
        """
        ``float64`` array of shape ``(num_points, 3)``, use ``numpy.asarray()`` to access data: Points coordinates.
        """
    @points.setter
    def points(self, arg0: open3d.cpu.pybind.utility.Vector3dVector) -> None:
        ...
class RGBDImage(Geometry2D):
    """
    RGBDImage is for a pair of registered color and depth images, viewed from the same view, of the same resolution. If you have other format, convert it first.
    """
    @staticmethod
    def create_from_color_and_depth(color, depth, depth_scale = 1000.0, depth_trunc = 3.0, convert_rgb_to_intensity = True):
        """
        Function to make RGBDImage from color and depth image
        
        Args:
            color (open3d.geometry.Image): The color image.
            depth (open3d.geometry.Image): The depth image.
            depth_scale (float, optional, default=1000.0): The ratio to scale depth values. The depth values will first be scaled and then truncated.
            depth_trunc (float, optional, default=3.0): Depth values larger than ``depth_trunc`` gets truncated to 0. The depth values will first be scaled and then truncated.
            convert_rgb_to_intensity (bool, optional, default=True): Whether to convert RGB image to intensity image.
        
        Returns:
            open3d.geometry.RGBDImage
        """
    @staticmethod
    def create_from_nyu_format(color, depth, convert_rgb_to_intensity = True):
        """
        Function to make RGBDImage (for NYU format)
        
        Args:
            color (open3d.geometry.Image): The color image.
            depth (open3d.geometry.Image): The depth image.
            convert_rgb_to_intensity (bool, optional, default=True): Whether to convert RGB image to intensity image.
        
        Returns:
            open3d.geometry.RGBDImage
        """
    @staticmethod
    def create_from_redwood_format(color, depth, convert_rgb_to_intensity = True):
        """
        Function to make RGBDImage (for Redwood format)
        
        Args:
            color (open3d.geometry.Image): The color image.
            depth (open3d.geometry.Image): The depth image.
            convert_rgb_to_intensity (bool, optional, default=True): Whether to convert RGB image to intensity image.
        
        Returns:
            open3d.geometry.RGBDImage
        """
    @staticmethod
    def create_from_sun_format(color, depth, convert_rgb_to_intensity = True):
        """
        Function to make RGBDImage (for SUN format)
        
        Args:
            color (open3d.geometry.Image): The color image.
            depth (open3d.geometry.Image): The depth image.
            convert_rgb_to_intensity (bool, optional, default=True): Whether to convert RGB image to intensity image.
        
        Returns:
            open3d.geometry.RGBDImage
        """
    @staticmethod
    def create_from_tum_format(color, depth, convert_rgb_to_intensity = True):
        """
        Function to make RGBDImage (for TUM format)
        
        Args:
            color (open3d.geometry.Image): The color image.
            depth (open3d.geometry.Image): The depth image.
            convert_rgb_to_intensity (bool, optional, default=True): Whether to convert RGB image to intensity image.
        
        Returns:
            open3d.geometry.RGBDImage
        """
    def __init__(self) -> None:
        """
        Default constructor
        """
    def __repr__(self) -> str:
        ...
    @property
    def color(self) -> Image:
        """
        open3d.geometry.Image: The color image.
        """
    @color.setter
    def color(self, arg0: Image) -> None:
        ...
    @property
    def depth(self) -> Image:
        """
        open3d.geometry.Image: The depth image.
        """
    @depth.setter
    def depth(self, arg0: Image) -> None:
        ...
class SimplificationContraction:
    """
    Members:
    
      Average : The vertex positions are computed by the averaging.
    
      Quadric : The vertex positions are computed by minimizing the distance to the adjacent triangle planes.
    """
    Average: typing.ClassVar[SimplificationContraction]  # value = <SimplificationContraction.Average: 0>
    Quadric: typing.ClassVar[SimplificationContraction]  # value = <SimplificationContraction.Quadric: 1>
    __members__: typing.ClassVar[dict[str, SimplificationContraction]]  # value = {'Average': <SimplificationContraction.Average: 0>, 'Quadric': <SimplificationContraction.Quadric: 1>}
    def __eq__(self, other: typing.Any) -> bool:
        ...
    def __getstate__(self) -> int:
        ...
    def __hash__(self) -> int:
        ...
    def __index__(self) -> int:
        ...
    def __init__(self, value: int) -> None:
        ...
    def __int__(self) -> int:
        ...
    def __ne__(self, other: typing.Any) -> bool:
        ...
    def __repr__(self) -> str:
        ...
    def __setstate__(self, state: int) -> None:
        ...
    def __str__(self) -> str:
        ...
    @property
    def name(self) -> str:
        ...
    @property
    def value(self) -> int:
        ...
class TetraMesh(MeshBase):
    """
    TetraMesh class. Tetra mesh contains vertices and tetrahedra represented by the indices to the vertices.
    """
    @staticmethod
    def create_from_point_cloud(point_cloud):
        """
        Function to create a tetrahedral mesh from a point cloud.
        
        Args:
            point_cloud (open3d.geometry.PointCloud): A PointCloud.
        
        Returns:
            Tuple[open3d.geometry.TetraMesh, List[int]]
        """
    def __add__(self, arg0: TetraMesh) -> TetraMesh:
        ...
    def __copy__(self) -> TetraMesh:
        ...
    def __deepcopy__(self, arg0: dict) -> TetraMesh:
        ...
    def __iadd__(self, arg0: TetraMesh) -> TetraMesh:
        ...
    @typing.overload
    def __init__(self) -> None:
        """
        Default constructor
        """
    @typing.overload
    def __init__(self, arg0: TetraMesh) -> None:
        """
        Copy constructor
        """
    @typing.overload
    def __init__(self, vertices: open3d.cpu.pybind.utility.Vector3dVector, tetras: open3d.cpu.pybind.utility.Vector4iVector) -> None:
        """
        Create a tetrahedra mesh from vertices and tetra indices
        """
    def __repr__(self) -> str:
        ...
    def extract_triangle_mesh(self, values, level):
        """
        Function that generates a triangle mesh of the specified iso-surface.
        
        Args:
            values (open3d.utility.DoubleVector): Vector with a scalar value for each vertex in the tetra mesh
            level (float): A scalar which defines the level-set to extract
        
        Returns:
            open3d.geometry.TriangleMesh
        """
    def has_tetras(self):
        """
        Returns ``True`` if the mesh contains tetras.
        
        Returns:
            bool
        """
    def has_vertices(self):
        """
        Returns ``True`` if the mesh contains vertices.
        
        Returns:
            bool
        """
    def remove_degenerate_tetras(self):
        """
        Function that removes degenerate tetras, i.e., tetras that references a single vertex multiple times in a single tetra. They are usually the product of removing duplicated vertices.
        
        Returns:
            open3d.geometry.TetraMesh
        """
    def remove_duplicated_tetras(self):
        """
        Function that removes duplicated tetras, i.e., removes tetras that reference the same four vertices, independent of their order.
        
        Returns:
            open3d.geometry.TetraMesh
        """
    def remove_duplicated_vertices(self):
        """
        Function that removes duplicated vertices, i.e., vertices that have identical coordinates.
        
        Returns:
            open3d.geometry.TetraMesh
        """
    def remove_unreferenced_vertices(self):
        """
        This function removes vertices from the tetra mesh that are not referenced in any tetra of the mesh.
        
        Returns:
            open3d.geometry.TetraMesh
        """
    @property
    def tetras(self) -> open3d.cpu.pybind.utility.Vector4iVector:
        """
        ``int64`` array of shape ``(num_tetras, 4)``, use ``numpy.asarray()`` to access data: List of tetras denoted by the index of points forming the tetra.
        """
    @tetras.setter
    def tetras(self, arg0: open3d.cpu.pybind.utility.Vector4iVector) -> None:
        ...
    @property
    def vertices(self) -> open3d.cpu.pybind.utility.Vector3dVector:
        """
        ``float64`` array of shape ``(num_vertices, 3)``, use ``numpy.asarray()`` to access data: Vertex coordinates.
        """
    @vertices.setter
    def vertices(self, arg0: open3d.cpu.pybind.utility.Vector3dVector) -> None:
        ...
class TriangleMesh(MeshBase):
    """
    TriangleMesh class. Triangle mesh contains vertices and triangles represented by the indices to the vertices. Optionally, the mesh may also contain triangle normals, vertex normals and vertex colors.
    """
    @staticmethod
    def create_arrow(cylinder_radius = 1.0, cone_radius = 1.5, cylinder_height = 5.0, cone_height = 4.0, resolution = 20, cylinder_split = 4, cone_split = 1):
        """
        Factory function to create an arrow mesh
        
        Args:
            cylinder_radius (float, optional, default=1.0): The radius of the cylinder.
            cone_radius (float, optional, default=1.5): The radius of the cone.
            cylinder_height (float, optional, default=5.0): The height of the cylinder. The cylinder is from (0, 0, 0) to (0, 0, cylinder_height)
            cone_height (float, optional, default=4.0): The height of the cone. The axis of the cone will be from (0, 0, cylinder_height) to (0, 0, cylinder_height + cone_height)
            resolution (int, optional, default=20): The cone will be split into ``resolution`` segments.
            cylinder_split (int, optional, default=4): The ``cylinder_height`` will be split into ``cylinder_split`` segments.
            cone_split (int, optional, default=1): The ``cone_height`` will be split into ``cone_split`` segments.
        
        Returns:
            open3d.geometry.TriangleMesh
        """
    @staticmethod
    def create_box(width = 1.0, height = 1.0, depth = 1.0, create_uv_map = False, map_texture_to_each_face = False):
        """
        Factory function to create a box. The left bottom corner on the front will be placed at (0, 0, 0), and default UV map, maps the entire texture to each face.
        
        Args:
            width (float, optional, default=1.0): x-directional length.
            height (float, optional, default=1.0): y-directional length.
            depth (float, optional, default=1.0): z-directional length.
            create_uv_map (bool, optional, default=False): Add default uv map to the mesh.
            map_texture_to_each_face (bool, optional, default=False): Map entire texture to each face.
        
        Returns:
            open3d.geometry.TriangleMesh
        """
    @staticmethod
    def create_cone(radius = 1.0, height = 2.0, resolution = 20, split = 1, create_uv_map = False):
        """
        Factory function to create a cone mesh.
        
        Args:
            radius (float, optional, default=1.0): The radius of the cone.
            height (float, optional, default=2.0): The height of the cone. The axis of the cone will be from (0, 0, 0) to (0, 0, height).
            resolution (int, optional, default=20): The circle will be split into ``resolution`` segments
            split (int, optional, default=1): The ``height`` will be split into ``split`` segments.
            create_uv_map (bool, optional, default=False): Add default uv map to the mesh.
        
        Returns:
            open3d.geometry.TriangleMesh
        """
    @staticmethod
    def create_coordinate_frame(size = 1.0, origin = ...):
        """
        Factory function to create a coordinate frame mesh. The coordinate frame will be centered at ``origin``. The x, y, z axis will be rendered as red, green, and blue arrows respectively.
        
        Args:
            size (float, optional, default=1.0): The size of the coordinate frame.
            origin (numpy.ndarray[numpy.float64[3, 1]], optional, default=array([0., 0., 0.])): The origin of the coordinate frame.
        
        Returns:
            open3d.geometry.TriangleMesh
        """
    @staticmethod
    def create_cylinder(radius = 1.0, height = 2.0, resolution = 20, split = 4, create_uv_map = False):
        """
        Factory function to create a cylinder mesh.
        
        Args:
            radius (float, optional, default=1.0): The radius of the cylinder.
            height (float, optional, default=2.0): The height of the cylinder. The axis of the cylinder will be from (0, 0, -height/2) to (0, 0, height/2).
            resolution (int, optional, default=20):  The circle will be split into ``resolution`` segments
            split (int, optional, default=4): The ``height`` will be split into ``split`` segments.
            create_uv_map (bool, optional, default=False): Add default uv map to the mesh.
        
        Returns:
            open3d.geometry.TriangleMesh
        """
    @staticmethod
    def create_from_oriented_bounding_box(obox, scale = ..., create_uv_map = False):
        """
        Factory function to create a solid oriented bounding box.
        
        Args:
            obox (open3d.geometry.OrientedBoundingBox): OrientedBoundingBox object to create mesh of.
            scale (numpy.ndarray[numpy.float64[3, 1]], optional, default=array([1., 1., 1.])): scale factor along each direction of OrientedBoundingBox
            create_uv_map (bool, optional, default=False): Add default uv map to the mesh.
        
        Returns:
            open3d.geometry.TriangleMesh
        """
    @staticmethod
    def create_from_point_cloud_alpha_shape(*args, **kwargs):
        """
        create_from_point_cloud_alpha_shape(*args, **kwargs)
        Overloaded function.
        
        
        1. create_from_point_cloud_alpha_shape(pcd, alpha)
            Alpha shapes are a generalization of the convex hull. With decreasing alpha value the shape schrinks and creates cavities. See Edelsbrunner and Muecke, "Three-Dimensional Alpha Shapes", 1994.
        
        Args:
            pcd (open3d.geometry.PointCloud): PointCloud from which the TriangleMesh surface is reconstructed.
            alpha (float): Parameter to control the shape. A very big value will give a shape close to the convex hull.
        
        Returns:
            open3d.geometry.TriangleMesh
        
        2. create_from_point_cloud_alpha_shape(pcd, alpha, tetra_mesh, pt_map)
            Alpha shapes are a generalization of the convex hull. With decreasing alpha value the shape shrinks and creates cavities. See Edelsbrunner and Muecke, "Three-Dimensional Alpha Shapes", 1994.
        
        Args:
            pcd (open3d.geometry.PointCloud): PointCloud from which the TriangleMesh surface is reconstructed.
            alpha (float): Parameter to control the shape. A very big value will give a shape close to the convex hull.
            tetra_mesh (open3d.geometry.TetraMesh): If not None, than uses this to construct the alpha shape. Otherwise, TetraMesh is computed from pcd.
            pt_map (List[int]): Optional map from tetra_mesh vertex indices to pcd points.
        
        Returns:
            open3d.geometry.TriangleMesh
        """
    @staticmethod
    def create_from_point_cloud_ball_pivoting(pcd, radii):
        """
        Function that computes a triangle mesh from a oriented PointCloud. This implements the Ball Pivoting algorithm proposed in F. Bernardini et al., "The ball-pivoting algorithm for surface reconstruction", 1999. The implementation is also based on the algorithms outlined in Digne, "An Analysis and Implementation of a Parallel Ball Pivoting Algorithm", 2014. The surface reconstruction is done by rolling a ball with a given radius over the point cloud, whenever the ball touches three points a triangle is created.
        
        Args:
            pcd (open3d.geometry.PointCloud): PointCloud from which the TriangleMesh surface is reconstructed. Has to contain normals.
            radii (open3d.utility.DoubleVector): The radii of the ball that are used for the surface reconstruction.
        
        Returns:
            open3d.geometry.TriangleMesh
        """
    @staticmethod
    def create_from_point_cloud_poisson(pcd, depth = 8, width = 0, scale = 1.1, linear_fit = False, n_threads = -1):
        """
        Function that computes a triangle mesh from a oriented PointCloud pcd. This implements the Screened Poisson Reconstruction proposed in Kazhdan and Hoppe, "Screened Poisson Surface Reconstruction", 2013. This function uses the original implementation by Kazhdan. See https://github.com/mkazhdan/PoissonRecon
        
        Args:
            pcd (open3d.geometry.PointCloud): PointCloud from which the TriangleMesh surface is reconstructed. Has to contain normals.
            depth (int, optional, default=8): Maximum depth of the tree that will be used for surface reconstruction. Running at depth d corresponds to solving on a grid whose resolution is no larger than 2^d x 2^d x 2^d. Note that since the reconstructor adapts the octree to the sampling density, the specified reconstruction depth is only an upper bound.
            width (float, optional, default=0): Specifies the target width of the finest level octree cells. This parameter is ignored if depth is specified
            scale (float, optional, default=1.1): Specifies the ratio between the diameter of the cube used for reconstruction and the diameter of the samples' bounding cube.
            linear_fit (bool, optional, default=False): If true, the reconstructor will use linear interpolation to estimate the positions of iso-vertices.
            n_threads (int, optional, default=-1): Number of threads used for reconstruction. Set to -1 to automatically determine it.
        
        Returns:
            Tuple[open3d.geometry.TriangleMesh, open3d.utility.DoubleVector]
        """
    @staticmethod
    def create_icosahedron(radius = 1.0, create_uv_map = False):
        """
        Factory function to create a icosahedron. The centroid of the mesh will be placed at (0, 0, 0) and the vertices have a distance of radius to the center.
        
        Args:
            radius (float, optional, default=1.0): Distance from centroid to mesh vetices.
            create_uv_map (bool, optional, default=False): Add default uv map to the mesh.
        
        Returns:
            open3d.geometry.TriangleMesh
        """
    @staticmethod
    def create_mobius(length_split = 70, width_split = 15, twists = 1, raidus = 1, flatness = 1, width = 1, scale = 1):
        """
        Factory function to create a Mobius strip.
        
        Args:
            length_split (int, optional, default=70): The number of segments along the Mobius strip.
            width_split (int, optional, default=15): The number of segments along the width of the Mobius strip.
            twists (int, optional, default=1): Number of twists of the Mobius strip.
            raidus (float, optional, default=1)
            flatness (float, optional, default=1): Controls the flatness/height of the Mobius strip.
            width (float, optional, default=1): Width of the Mobius strip.
            scale (float, optional, default=1): Scale the complete Mobius strip.
        
        Returns:
            open3d.geometry.TriangleMesh
        """
    @staticmethod
    def create_octahedron(radius = 1.0, create_uv_map = False):
        """
        Factory function to create a octahedron. The centroid of the mesh will be placed at (0, 0, 0) and the vertices have a distance of radius to the center.
        
        Args:
            radius (float, optional, default=1.0): Distance from centroid to mesh vetices.
            create_uv_map (bool, optional, default=False): Add default uv map to the mesh.
        
        Returns:
            open3d.geometry.TriangleMesh
        """
    @staticmethod
    def create_sphere(radius = 1.0, resolution = 20, create_uv_map = False):
        """
        Factory function to create a sphere mesh centered at (0, 0, 0).
        
        Args:
            radius (float, optional, default=1.0): The radius of the sphere.
            resolution (int, optional, default=20): The resolution of the sphere. The longitues will be split into ``resolution`` segments (i.e. there are ``resolution + 1`` latitude lines including the north and south pole). The latitudes will be split into ```2 * resolution`` segments (i.e. there are ``2 * resolution`` longitude lines.)
            create_uv_map (bool, optional, default=False): Add default uv map to the mesh.
        
        Returns:
            open3d.geometry.TriangleMesh
        """
    @staticmethod
    def create_tetrahedron(radius = 1.0, create_uv_map = False):
        """
        Factory function to create a tetrahedron. The centroid of the mesh will be placed at (0, 0, 0) and the vertices have a distance of radius to the center.
        
        Args:
            radius (float, optional, default=1.0): Distance from centroid to mesh vetices.
            create_uv_map (bool, optional, default=False): Add default uv map to the mesh.
        
        Returns:
            open3d.geometry.TriangleMesh
        """
    @staticmethod
    def create_torus(torus_radius = 1.0, tube_radius = 0.5, radial_resolution = 30, tubular_resolution = 20):
        """
        Factory function to create a torus mesh.
        
        Args:
            torus_radius (float, optional, default=1.0): The radius from the center of the torus to the center of the tube.
            tube_radius (float, optional, default=0.5): The radius of the torus tube.
            radial_resolution (int, optional, default=30): The number of segments along the radial direction.
            tubular_resolution (int, optional, default=20): The number of segments along the tubular direction.
        
        Returns:
            open3d.geometry.TriangleMesh
        """
    @staticmethod
    def crop(*args, **kwargs):
        """
        crop(*args, **kwargs)
        Overloaded function.
        
        
        1. crop(self, bounding_box)
            Function to crop input TriangleMesh into output TriangleMesh
        
        Args:
            bounding_box (open3d.geometry.AxisAlignedBoundingBox): AxisAlignedBoundingBox to crop points
        
        Returns:
            open3d.geometry.TriangleMesh
        
        2. crop(self, bounding_box)
            Function to crop input TriangleMesh into output TriangleMesh
        
        Args:
            bounding_box (open3d.geometry.OrientedBoundingBox): AxisAlignedBoundingBox to crop points
        
        Returns:
            open3d.geometry.TriangleMesh
        """
    @staticmethod
    def deform_as_rigid_as_possible(*args, **kwargs):
        """
        This function deforms the mesh using the method by Sorkine and Alexa, 'As-Rigid-As-Possible Surface Modeling', 2007
        
        Args:
            constraint_vertex_indices (open3d.utility.IntVector): Indices of the triangle vertices that should be constrained by the vertex positions in constraint_vertex_positions.
            constraint_vertex_positions (open3d.utility.Vector3dVector): Vertex positions used for the constraints.
            max_iter (int): Maximum number of iterations to minimize energy functional.
            energy (open3d.geometry.DeformAsRigidAsPossibleEnergy, optional, default=<DeformAsRigidAsPossibleEnergy.Spokes: 0>): Energy model that is minimized in the deformation process
            smoothed_alpha (float, optional, default=0.01): trade-off parameter for the smoothed energy functional for the regularization term.
        
        Returns:
            open3d.geometry.TriangleMesh
        """
    @staticmethod
    def filter_sharpen(*args, **kwargs):
        """
        Function to sharpen triangle mesh. The output value (:math:`v_o`) is the input value (:math:`v_i`) plus strength times the input value minus he sum of he adjacent values. :math:`v_o = v_i x strength (v_i * |N| - \\sum_{n \\in N} v_n)`
        
        Args:
            number_of_iterations (int, optional, default=1):  Number of repetitions of this operation
            strength (float, optional, default=1): Filter parameter.
            filter_scope (open3d.geometry.FilterScope, optional, default=<FilterScope.All: 0>)
        
        Returns:
            open3d.geometry.TriangleMesh
        """
    @staticmethod
    def filter_smooth_laplacian(*args, **kwargs):
        """
        Function to smooth triangle mesh using Laplacian. :math:`v_o = v_i \\cdot \\lambda (sum_{n \\in N} w_n v_n - v_i)`, with :math:`v_i` being the input value, :math:`v_o` the output value, :math:`N` is the  set of adjacent neighbours, :math:`w_n` is the weighting of the neighbour based on the inverse distance (closer neighbours have higher weight), and lambda_filter is the smoothing parameter.
        
        Args:
            number_of_iterations (int, optional, default=1):  Number of repetitions of this operation
            lambda_filter (float, optional, default=0.5): Filter parameter.
            filter_scope (open3d.geometry.FilterScope, optional, default=<FilterScope.All: 0>)
        
        Returns:
            open3d.geometry.TriangleMesh
        """
    @staticmethod
    def filter_smooth_simple(*args, **kwargs):
        """
        Function to smooth triangle mesh with simple neighbour average. :math:`v_o = \\frac{v_i + \\sum_{n \\in N} v_n)}{|N| + 1}`, with :math:`v_i` being the input value, :math:`v_o` the output value, and :math:`N` is the set of adjacent neighbours.
        
        Args:
            number_of_iterations (int, optional, default=1):  Number of repetitions of this operation
            filter_scope (open3d.geometry.FilterScope, optional, default=<FilterScope.All: 0>)
        
        Returns:
            open3d.geometry.TriangleMesh
        """
    @staticmethod
    def filter_smooth_taubin(*args, **kwargs):
        """
        Function to smooth triangle mesh using method of Taubin, "Curve and Surface Smoothing Without Shrinkage", 1995. Applies in each iteration two times filter_smooth_laplacian, first with filter parameter lambda_filter and second with filter parameter mu as smoothing parameter. This method avoids shrinkage of the triangle mesh.
        
        Args:
            number_of_iterations (int, optional, default=1):  Number of repetitions of this operation
            lambda_filter (float, optional, default=0.5): Filter parameter.
            mu (float, optional, default=-0.53): Filter parameter.
            filter_scope (open3d.geometry.FilterScope, optional, default=<FilterScope.All: 0>)
        
        Returns:
            open3d.geometry.TriangleMesh
        """
    @staticmethod
    def simplify_vertex_clustering(*args, **kwargs):
        """
        Function to simplify mesh using vertex clustering.
        
        Args:
            voxel_size (float): The size of the voxel within vertices are pooled.
            contraction (open3d.geometry.SimplificationContraction, optional, default=<SimplificationContraction.Average: 0>): Method to aggregate vertex information. Average computes a simple average, Quadric minimizes the distance to the adjacent planes.
        
        Returns:
            open3d.geometry.TriangleMesh
        """
    def __add__(self, arg0: TriangleMesh) -> TriangleMesh:
        ...
    def __copy__(self) -> TriangleMesh:
        ...
    def __deepcopy__(self, arg0: dict) -> TriangleMesh:
        ...
    def __iadd__(self, arg0: TriangleMesh) -> TriangleMesh:
        ...
    @typing.overload
    def __init__(self) -> None:
        """
        Default constructor
        """
    @typing.overload
    def __init__(self, arg0: TriangleMesh) -> None:
        """
        Copy constructor
        """
    @typing.overload
    def __init__(self, vertices: open3d.cpu.pybind.utility.Vector3dVector, triangles: open3d.cpu.pybind.utility.Vector3iVector) -> None:
        """
        Create a triangle mesh from vertices and triangle indices
        """
    def __repr__(self) -> str:
        ...
    def cluster_connected_triangles(self):
        """
        Function that clusters connected triangles, i.e., triangles that are connected via edges are assigned the same cluster index. This function returns an array that contains the cluster index per triangle, a second array contains the number of triangles per cluster, and a third vector contains the surface area per cluster.
        
        Returns:
            Tuple[open3d.utility.IntVector, List[int], open3d.utility.DoubleVector]
        """
    def compute_adjacency_list(self):
        """
        Function to compute adjacency list, call before adjacency list is needed
        
        Returns:
            open3d.geometry.TriangleMesh
        """
    def compute_convex_hull(self):
        """
        Computes the convex hull of the triangle mesh.
        
        Returns:
            Tuple[open3d.geometry.TriangleMesh, List[int]]
        """
    def compute_triangle_normals(self, normalized = True):
        """
        Function to compute triangle normals, usually called before rendering
        
        Args:
            normalized (bool, optional, default=True)
        
        Returns:
            open3d.geometry.TriangleMesh
        """
    def compute_vertex_normals(self, normalized = True):
        """
        Function to compute vertex normals, usually called before rendering
        
        Args:
            normalized (bool, optional, default=True)
        
        Returns:
            open3d.geometry.TriangleMesh
        """
    def euler_poincare_characteristic(self):
        """
        Function that computes the Euler-Poincaré characteristic, i.e., V + F - E, where V is the number of vertices, F is the number of triangles, and E is the number of edges.
        
        Returns:
            int
        """
    def get_non_manifold_edges(self, allow_boundary_edges = True):
        """
        Get list of non-manifold edges.
        
        Args:
            allow_boundary_edges (bool, optional, default=True): If true, than non-manifold edges are defined as edges with more than two adjacent triangles, otherwise each edge that is not adjacent to two triangles is defined as non-manifold.
        
        Returns:
            open3d.utility.Vector2iVector
        """
    def get_non_manifold_vertices(self):
        """
        Returns a list of indices to non-manifold vertices.
        
        Returns:
            open3d.utility.IntVector
        """
    def get_self_intersecting_triangles(self):
        """
        Returns a list of indices to triangles that intersect the mesh.
        
        Returns:
            open3d.utility.Vector2iVector
        """
    def get_surface_area(self) -> float:
        """
        Function that computes the surface area of the mesh, i.e. the sum of the individual triangle surfaces.
        """
    def get_volume(self) -> float:
        """
        Function that computes the volume of the mesh, under the condition that it is watertight and orientable.
        """
    def has_adjacency_list(self):
        """
        Returns ``True`` if the mesh contains adjacency normals.
        
        Returns:
            bool
        """
    def has_textures(self):
        """
        Returns ``True`` if the mesh contains a texture image.
        
        Returns:
            bool
        """
    def has_triangle_material_ids(self):
        """
        Returns ``True`` if the mesh contains material ids.
        
        Returns:
            bool
        """
    def has_triangle_normals(self):
        """
        Returns ``True`` if the mesh contains triangle normals.
        
        Returns:
            bool
        """
    def has_triangle_uvs(self):
        """
        Returns ``True`` if the mesh contains uv coordinates.
        
        Returns:
            bool
        """
    def has_triangles(self):
        """
        Returns ``True`` if the mesh contains triangles.
        
        Returns:
            bool
        """
    def has_vertex_colors(self):
        """
        Returns ``True`` if the mesh contains vertex colors.
        
        Returns:
            bool
        """
    def has_vertex_normals(self):
        """
        Returns ``True`` if the mesh contains vertex normals.
        
        Returns:
            bool
        """
    def has_vertices(self):
        """
        Returns ``True`` if the mesh contains vertices.
        
        Returns:
            bool
        """
    def is_edge_manifold(self, allow_boundary_edges = True):
        """
        Tests if the triangle mesh is edge manifold.
        
        Args:
            allow_boundary_edges (bool, optional, default=True): If true, than non-manifold edges are defined as edges with more than two adjacent triangles, otherwise each edge that is not adjacent to two triangles is defined as non-manifold.
        
        Returns:
            bool
        """
    def is_intersecting(self, arg0):
        """
        Tests if the triangle mesh is intersecting the other triangle mesh.
        
        Args:
            arg0 (open3d.geometry.TriangleMesh)
        
        Returns:
            bool
        """
    def is_orientable(self):
        """
        Tests if the triangle mesh is orientable.
        
        Returns:
            bool
        """
    def is_self_intersecting(self):
        """
        Tests if the triangle mesh is self-intersecting.
        
        Returns:
            bool
        """
    def is_vertex_manifold(self):
        """
        Tests if all vertices of the triangle mesh are manifold.
        
        Returns:
            bool
        """
    def is_watertight(self):
        """
        Tests if the triangle mesh is watertight.
        
        Returns:
            bool
        """
    def merge_close_vertices(self, eps):
        """
        Function that will merge close by vertices to a single one. The vertex position, normal and color will be the average of the vertices. The parameter eps defines the maximum distance of close by vertices.  This function might help to close triangle soups.
        
        Args:
            eps (float): Parameter that defines the distance between close vertices.
        
        Returns:
            open3d.geometry.TriangleMesh
        """
    def normalize_normals(self):
        """
        Normalize both triangle normals and vertex normals to length 1.
        
        Returns:
            open3d.geometry.TriangleMesh
        """
    def orient_triangles(self):
        """
        If the mesh is orientable this function orients all triangles such that all normals point towards the same direction.
        
        Returns:
            bool
        """
    def paint_uniform_color(self, arg0):
        """
        Assigns each vertex in the TriangleMesh the same color.
        
        Args:
            arg0 (numpy.ndarray[numpy.float64[3, 1]])
        
        Returns:
            open3d.geometry.MeshBase
        """
    def remove_degenerate_triangles(self):
        """
        Function that removes degenerate triangles, i.e., triangles that references a single vertex multiple times in a single triangle. They are usually the product of removing duplicated vertices.
        
        Returns:
            open3d.geometry.TriangleMesh
        """
    def remove_duplicated_triangles(self):
        """
        Function that removes duplicated triangles, i.e., removes triangles that reference the same three vertices and have the same orientation.
        
        Returns:
            open3d.geometry.TriangleMesh
        """
    def remove_duplicated_vertices(self):
        """
        Function that removes duplicated vertices, i.e., vertices that have identical coordinates.
        
        Returns:
            open3d.geometry.TriangleMesh
        """
    def remove_non_manifold_edges(self):
        """
        Function that removes all non-manifold edges, by successively deleting  triangles with the smallest surface area adjacent to the non-manifold edge until the number of adjacent triangles to the edge is `<= 2`.
        
        Returns:
            open3d.geometry.TriangleMesh
        """
    def remove_triangles_by_index(self, triangle_indices):
        """
        This function removes the triangles with index in triangle_indices.  Call remove_unreferenced_vertices to clean up vertices afterwards.
        
        Args:
            triangle_indices (List[int]): 1D array of triangle indices that should be removed from the TriangleMesh.
        
        Returns:
            None
        """
    def remove_triangles_by_mask(self, triangle_mask):
        """
        This function removes the triangles where triangle_mask is set to true.  Call remove_unreferenced_vertices to clean up vertices afterwards.
        
        Args:
            triangle_mask (List[bool]): 1D bool array, True values indicate triangles that should be removed.
        
        Returns:
            None
        """
    def remove_unreferenced_vertices(self):
        """
        This function removes vertices from the triangle mesh that are not referenced in any triangle of the mesh.
        
        Returns:
            open3d.geometry.TriangleMesh
        """
    def remove_vertices_by_index(self, vertex_indices):
        """
        This function removes the vertices with index in vertex_indices. Note that also all triangles associated with the vertices are removed.
        
        Args:
            vertex_indices (List[int]): 1D array of vertex indices that should be removed from the TriangleMesh.
        
        Returns:
            None
        """
    def remove_vertices_by_mask(self, vertex_mask):
        """
        This function removes the vertices that are masked in vertex_mask. Note that also all triangles associated with the vertices are removed.
        
        Args:
            vertex_mask (List[bool]): 1D bool array, True values indicate vertices that should be removed.
        
        Returns:
            None
        """
    def sample_points_poisson_disk(self, number_of_points, init_factor = 5, pcl = None, use_triangle_normal = False):
        """
        Function to sample points from the mesh, where each point has approximately the same distance to the neighbouring points (blue noise). Method is based on Yuksel, "Sample Elimination for Generating Poisson Disk Sample Sets", EUROGRAPHICS, 2015.
        
        Args:
            number_of_points (int): Number of points that should be sampled.
            init_factor (float, optional, default=5): Factor for the initial uniformly sampled PointCloud. This init PointCloud is used for sample elimination.
            pcl (open3d.geometry.PointCloud, optional, default=None): Initial PointCloud that is used for sample elimination. If this parameter is provided the init_factor is ignored.
            use_triangle_normal (bool, optional, default=False): If True assigns the triangle normals instead of the interpolated vertex normals to the returned points. The triangle normals will be computed and added to the mesh if necessary.
        
        Returns:
            open3d.geometry.PointCloud
        """
    def sample_points_uniformly(self, number_of_points = 100, use_triangle_normal = False):
        """
        Function to uniformly sample points from the mesh.
        
        Args:
            number_of_points (int, optional, default=100): Number of points that should be uniformly sampled.
            use_triangle_normal (bool, optional, default=False): If True assigns the triangle normals instead of the interpolated vertex normals to the returned points. The triangle normals will be computed and added to the mesh if necessary.
        
        Returns:
            open3d.geometry.PointCloud
        """
    def select_by_index(self, indices, cleanup = True):
        """
        Function to select mesh from input triangle mesh into output triangle mesh. ``input``: The input triangle mesh. ``indices``: Indices of vertices to be selected.
        
        Args:
            indices (List[int]): Indices of vertices to be selected.
            cleanup (bool, optional, default=True): If true calls number of mesh cleanup functions to remove unreferenced vertices and degenerate triangles
        
        Returns:
            open3d.geometry.TriangleMesh
        """
    def simplify_quadric_decimation(self, target_number_of_triangles, maximum_error = ..., boundary_weight = 1.0):
        """
        Function to simplify mesh using Quadric Error Metric Decimation by Garland and Heckbert
        
        Args:
            target_number_of_triangles (int): The number of triangles that the simplified mesh should have. It is not guaranteed that this number will be reached.
            maximum_error (float, optional, default=inf): The maximum error where a vertex is allowed to be merged
            boundary_weight (float, optional, default=1.0): A weight applied to edge vertices used to preserve boundaries
        
        Returns:
            open3d.geometry.TriangleMesh
        """
    def subdivide_loop(self, number_of_iterations = 1):
        """
        Function subdivide mesh using Loop's algorithm. Loop, "Smooth subdivision surfaces based on triangles", 1987.
        
        Args:
            number_of_iterations (int, optional, default=1): Number of iterations. A single iteration splits each triangle into four triangles.
        
        Returns:
            open3d.geometry.TriangleMesh
        """
    def subdivide_midpoint(self, number_of_iterations = 1):
        """
        Function subdivide mesh using midpoint algorithm.
        
        Args:
            number_of_iterations (int, optional, default=1): Number of iterations. A single iteration splits each triangle into four triangles that cover the same surface.
        
        Returns:
            open3d.geometry.TriangleMesh
        """
    @property
    def adjacency_list(self) -> list[set[int]]:
        """
        List of Sets: The set ``adjacency_list[i]`` contains the indices of adjacent vertices of vertex i.
        """
    @adjacency_list.setter
    def adjacency_list(self, arg0: list[set[int]]) -> None:
        ...
    @property
    def textures(self) -> list[...]:
        """
        open3d.geometry.Image: The texture images.
        """
    @textures.setter
    def textures(self, arg0: list[...]) -> None:
        ...
    @property
    def triangle_material_ids(self) -> open3d.cpu.pybind.utility.IntVector:
        """
        `int` array of shape ``(num_trianges, 1)``, use ``numpy.asarray()`` to access data: material index associated with each triangle
        """
    @triangle_material_ids.setter
    def triangle_material_ids(self, arg0: open3d.cpu.pybind.utility.IntVector) -> None:
        ...
    @property
    def triangle_normals(self) -> open3d.cpu.pybind.utility.Vector3dVector:
        """
        ``float64`` array of shape ``(num_triangles, 3)``, use ``numpy.asarray()`` to access data: Triangle normals.
        """
    @triangle_normals.setter
    def triangle_normals(self, arg0: open3d.cpu.pybind.utility.Vector3dVector) -> None:
        ...
    @property
    def triangle_uvs(self) -> open3d.cpu.pybind.utility.Vector2dVector:
        """
        ``float64`` array of shape ``(3 * num_triangles, 2)``, use ``numpy.asarray()`` to access data: List of uvs denoted by the index of points forming the triangle.
        """
    @triangle_uvs.setter
    def triangle_uvs(self, arg0: open3d.cpu.pybind.utility.Vector2dVector) -> None:
        ...
    @property
    def triangles(self) -> open3d.cpu.pybind.utility.Vector3iVector:
        """
        ``int`` array of shape ``(num_triangles, 3)``, use ``numpy.asarray()`` to access data: List of triangles denoted by the index of points forming the triangle.
        """
    @triangles.setter
    def triangles(self, arg0: open3d.cpu.pybind.utility.Vector3iVector) -> None:
        ...
    @property
    def vertex_colors(self) -> open3d.cpu.pybind.utility.Vector3dVector:
        """
        ``float64`` array of shape ``(num_vertices, 3)``, range ``[0, 1]`` , use ``numpy.asarray()`` to access data: RGB colors of vertices.
        """
    @vertex_colors.setter
    def vertex_colors(self, arg0: open3d.cpu.pybind.utility.Vector3dVector) -> None:
        ...
    @property
    def vertex_normals(self) -> open3d.cpu.pybind.utility.Vector3dVector:
        """
        ``float64`` array of shape ``(num_vertices, 3)``, use ``numpy.asarray()`` to access data: Vertex normals.
        """
    @vertex_normals.setter
    def vertex_normals(self, arg0: open3d.cpu.pybind.utility.Vector3dVector) -> None:
        ...
    @property
    def vertices(self) -> open3d.cpu.pybind.utility.Vector3dVector:
        """
        ``float64`` array of shape ``(num_vertices, 3)``, use ``numpy.asarray()`` to access data: Vertex coordinates.
        """
    @vertices.setter
    def vertices(self, arg0: open3d.cpu.pybind.utility.Vector3dVector) -> None:
        ...
class Voxel:
    """
    Base Voxel class, containing grid id and color
    """
    def __copy__(self) -> Voxel:
        ...
    def __deepcopy__(self, arg0: dict) -> Voxel:
        ...
    @typing.overload
    def __init__(self) -> None:
        """
        Default constructor
        """
    @typing.overload
    def __init__(self, arg0: Voxel) -> None:
        """
        Copy constructor
        """
    @typing.overload
    def __init__(self, grid_index: numpy.ndarray[numpy.int32[3, 1]]) -> None:
        ...
    @typing.overload
    def __init__(self, grid_index: numpy.ndarray[numpy.int32[3, 1]], color: numpy.ndarray[numpy.float64[3, 1]]) -> None:
        ...
    def __repr__(self) -> str:
        ...
    @property
    def color(self) -> numpy.ndarray[numpy.float64[3, 1]]:
        """
        Float64 numpy array of shape (3,): Color of the voxel.
        """
    @color.setter
    def color(self, arg0: numpy.ndarray[numpy.float64[3, 1]]) -> None:
        ...
    @property
    def grid_index(self) -> numpy.ndarray[numpy.int32[3, 1]]:
        """
        Int numpy array of shape (3,): Grid coordinate index of the voxel.
        """
    @grid_index.setter
    def grid_index(self, arg0: numpy.ndarray[numpy.int32[3, 1]]) -> None:
        ...
class VoxelGrid(Geometry3D):
    """
    VoxelGrid is a collection of voxels which are aligned in grid.
    """
    @staticmethod
    def create_dense(origin, color, voxel_size, width, height, depth):
        """
        Creates a voxel grid where every voxel is set (hence dense). This is a useful starting point for voxel carving
        
        Args:
            origin (numpy.ndarray[numpy.float64[3, 1]]): Coordinate center of the VoxelGrid
            color (numpy.ndarray[numpy.float64[3, 1]]): Voxel color for all voxels if the VoxelGrid.
            voxel_size (float): Voxel size of of the VoxelGrid construction.
            width (float): Spatial width extend of the VoxelGrid.
            height (float): Spatial height extend of the VoxelGrid.
            depth (float): Spatial depth extend of the VoxelGrid.
        
        Returns:
            open3d.geometry.VoxelGrid
        """
    @staticmethod
    def create_from_point_cloud(input, voxel_size):
        """
        Creates a VoxelGrid from a given PointCloud. The color value of a given  voxel is the average color value of the points that fall into it (if the PointCloud has colors). The bounds of the created VoxelGrid are computed from the PointCloud.
        
        Args:
            input (open3d.geometry.PointCloud): The input PointCloud
            voxel_size (float): Voxel size of of the VoxelGrid construction.
        
        Returns:
            open3d.geometry.VoxelGrid
        """
    @staticmethod
    def create_from_point_cloud_within_bounds(input, voxel_size, min_bound, max_bound):
        """
        Creates a VoxelGrid from a given PointCloud. The color value of a given voxel is the average color value of the points that fall into it (if the PointCloud has colors). The bounds of the created VoxelGrid are defined by the given parameters.
        
        Args:
            input (open3d.geometry.PointCloud): The input PointCloud
            voxel_size (float): Voxel size of of the VoxelGrid construction.
            min_bound (numpy.ndarray[numpy.float64[3, 1]]): Minimum boundary point for the VoxelGrid to create.
            max_bound (numpy.ndarray[numpy.float64[3, 1]]): Maximum boundary point for the VoxelGrid to create.
        
        Returns:
            open3d.geometry.VoxelGrid
        """
    @staticmethod
    def create_from_triangle_mesh(input, voxel_size):
        """
        Creates a VoxelGrid from a given TriangleMesh. No color information is converted. The bounds of the created VoxelGrid are computed from the  TriangleMesh.
        
        Args:
            input (open3d.geometry.TriangleMesh): The input TriangleMesh
            voxel_size (float): Voxel size of of the VoxelGrid construction.
        
        Returns:
            open3d.geometry.VoxelGrid
        """
    @staticmethod
    def create_from_triangle_mesh_within_bounds(input, voxel_size, min_bound, max_bound):
        """
        Creates a VoxelGrid from a given TriangleMesh. No color information is converted. The bounds of the created VoxelGrid are defined by the given parameters
        
        Args:
            input (open3d.geometry.TriangleMesh): The input TriangleMesh
            voxel_size (float): Voxel size of of the VoxelGrid construction.
            min_bound (numpy.ndarray[numpy.float64[3, 1]]): Minimum boundary point for the VoxelGrid to create.
            max_bound (numpy.ndarray[numpy.float64[3, 1]]): Maximum boundary point for the VoxelGrid to create.
        
        Returns:
            open3d.geometry.VoxelGrid
        """
    def __add__(self, arg0: VoxelGrid) -> VoxelGrid:
        ...
    def __copy__(self) -> VoxelGrid:
        ...
    def __deepcopy__(self, arg0: dict) -> VoxelGrid:
        ...
    def __iadd__(self, arg0: VoxelGrid) -> VoxelGrid:
        ...
    @typing.overload
    def __init__(self) -> None:
        """
        Default constructor
        """
    @typing.overload
    def __init__(self, arg0: VoxelGrid) -> None:
        """
        Copy constructor
        """
    def __repr__(self) -> str:
        ...
    def add_voxel(self, voxel):
        """
        Add a new voxel into the VoxelGrid.
        
        Args:
            voxel (open3d.geometry.Voxel)
        
        Returns:
            None
        """
    def carve_depth_map(self, depth_map, camera_params, keep_voxels_outside_image = False):
        """
        Remove all voxels from the VoxelGrid where none of the boundary points of the voxel projects to depth value that is smaller, or equal than the projected depth of the boundary point. If keep_voxels_outside_image is true then voxels are only carved if all boundary points project to a valid image location.
        
        Args:
            depth_map (open3d.geometry.Image): Depth map (Image) used for VoxelGrid carving.
            camera_params (open3d.camera.PinholeCameraParameters)
            keep_voxels_outside_image (bool, optional, default=False): retain voxels that don't project to pixels in the image
        
        Returns:
            open3d.geometry.VoxelGrid
        """
    def carve_silhouette(self, silhouette_mask, camera_params, keep_voxels_outside_image = False):
        """
        Remove all voxels from the VoxelGrid where none of the boundary points of the voxel projects to a valid mask pixel (pixel value > 0). If keep_voxels_outside_image is true then voxels are only carved if all boundary points project to a valid image location.
        
        Args:
            silhouette_mask (open3d.geometry.Image): Silhouette mask (Image) used for VoxelGrid carving.
            camera_params (open3d.camera.PinholeCameraParameters)
            keep_voxels_outside_image (bool, optional, default=False): retain voxels that don't project to pixels in the image
        
        Returns:
            open3d.geometry.VoxelGrid
        """
    def check_if_included(self, queries):
        """
        Element-wise check if a query in the list is included in the VoxelGrid. Queries are double precision and are mapped to the closest voxel.
        
        Args:
            queries (open3d.utility.Vector3dVector)
        
        Returns:
            List[bool]
        """
    def create_from_octree(self, octree):
        """
        Convert from Octree.
        
        Args:
            octree (open3d.geometry.Octree): geometry.Octree: The source octree.
        
        Returns:
            None
        """
    def get_voxel(self, point):
        """
        Returns voxel index given query point.
        
        Args:
            point (numpy.ndarray[numpy.float64[3, 1]]): The query point.
        
        Returns:
            numpy.ndarray[numpy.int32[3, 1]]
        """
    def get_voxel_bounding_points(self, index):
        """
        Returns the 8 bounding points of a voxel given its grid index.
        
        Args:
            index (numpy.ndarray[numpy.int32[3, 1]]): The grid index of the query voxel.
        
        Returns:
            open3d.utility.Vector3dVector
        """
    def get_voxel_center_coordinate(self, idx):
        """
        Returns the center coordinate of a voxel given its grid index.
        
        Args:
            idx (numpy.ndarray[numpy.int32[3, 1]]): The grid index of the query voxel.
        
        Returns:
            numpy.ndarray[numpy.float64[3, 1]]
        """
    def get_voxels(self) -> list[Voxel]:
        """
        Returns List of ``Voxel``: Voxels contained in voxel grid. Changes to the voxels returned from this methodare not reflected in the voxel grid.
        """
    def has_colors(self):
        """
        Returns ``True`` if the voxel grid contains voxel colors.
        
        Returns:
            bool
        """
    def has_voxels(self):
        """
        Returns ``True`` if the voxel grid contains voxels.
        
        Returns:
            bool
        """
    def remove_voxel(self, idx):
        """
        Remove a voxel given index.
        
        Args:
            idx (numpy.ndarray[numpy.int32[3, 1]]): The grid index of the target voxel.
        
        Returns:
            None
        """
    def to_octree(self, max_depth):
        """
        Convert to Octree.
        
        Args:
            max_depth (int): int: Maximum depth of the octree.
        
        Returns:
            open3d.geometry.Octree
        """
    @property
    def origin(self) -> numpy.ndarray[numpy.float64[3, 1]]:
        """
        ``float64`` vector of length 3: Coorindate of the origin point.
        """
    @origin.setter
    def origin(self, arg0: numpy.ndarray[numpy.float64[3, 1]]) -> None:
        ...
    @property
    def voxel_size(self) -> float:
        """
        ``float64`` Size of the voxel.
        """
    @voxel_size.setter
    def voxel_size(self, arg0: float) -> None:
        ...
def get_rotation_matrix_from_axis_angle(rotation: numpy.ndarray[numpy.float64[3, 1]]) -> numpy.ndarray[numpy.float64[3, 3]]:
    ...
def get_rotation_matrix_from_quaternion(rotation: numpy.ndarray[numpy.float64[4, 1]]) -> numpy.ndarray[numpy.float64[3, 3]]:
    ...
def get_rotation_matrix_from_xyz(rotation: numpy.ndarray[numpy.float64[3, 1]]) -> numpy.ndarray[numpy.float64[3, 3]]:
    ...
def get_rotation_matrix_from_xzy(rotation: numpy.ndarray[numpy.float64[3, 1]]) -> numpy.ndarray[numpy.float64[3, 3]]:
    ...
def get_rotation_matrix_from_yxz(rotation: numpy.ndarray[numpy.float64[3, 1]]) -> numpy.ndarray[numpy.float64[3, 3]]:
    ...
def get_rotation_matrix_from_yzx(rotation: numpy.ndarray[numpy.float64[3, 1]]) -> numpy.ndarray[numpy.float64[3, 3]]:
    ...
def get_rotation_matrix_from_zxy(rotation: numpy.ndarray[numpy.float64[3, 1]]) -> numpy.ndarray[numpy.float64[3, 3]]:
    ...
def get_rotation_matrix_from_zyx(rotation: numpy.ndarray[numpy.float64[3, 1]]) -> numpy.ndarray[numpy.float64[3, 3]]:
    ...
All: FilterScope  # value = <FilterScope.All: 0>
Average: SimplificationContraction  # value = <SimplificationContraction.Average: 0>
Color: FilterScope  # value = <FilterScope.Color: 1>
Gaussian3: ImageFilterType  # value = <ImageFilterType.Gaussian3: 0>
Gaussian5: ImageFilterType  # value = <ImageFilterType.Gaussian5: 1>
Gaussian7: ImageFilterType  # value = <ImageFilterType.Gaussian7: 2>
Normal: FilterScope  # value = <FilterScope.Normal: 2>
Quadric: SimplificationContraction  # value = <SimplificationContraction.Quadric: 1>
Smoothed: DeformAsRigidAsPossibleEnergy  # value = <DeformAsRigidAsPossibleEnergy.Smoothed: 1>
Sobel3dx: ImageFilterType  # value = <ImageFilterType.Sobel3dx: 3>
Sobel3dy: ImageFilterType  # value = <ImageFilterType.Sobel3dy: 4>
Spokes: DeformAsRigidAsPossibleEnergy  # value = <DeformAsRigidAsPossibleEnergy.Spokes: 0>
Vertex: FilterScope  # value = <FilterScope.Vertex: 3>
