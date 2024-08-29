import numpy as np


def iou(mat1: np.array, mat2: np.array):
    """
    mat1: [x1,y1,x2,y2]
    """
    x1_inter = max(mat1[0], mat2[0])
    y1_inter = max(mat1[1], mat2[1])
    x2_inter = min(mat1[2], mat2[2])
    y2_inter = min(mat1[3], mat2[3])

    inter_width = max(0, x2_inter - x1_inter)
    inter_height = max(0, y2_inter - y1_inter)
    inter_area = inter_width * inter_height

    area_mat1 = (mat1[2] - mat1[0]) * (mat1[3] - mat1[1])
    area_mat2 = (mat2[2] - mat2[0]) * (mat2[3] - mat2[1])
    total_area = area_mat1 + area_mat2
    union_area = total_area - inter_area

    iou = inter_area / union_area if union_area != 0 else 0
    return iou
