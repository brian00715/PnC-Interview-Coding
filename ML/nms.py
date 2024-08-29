from iou import iou
import numpy as np
import cv2
import sys


def nms(boxes: list, scores: list, iou_th: float):
    boxes = np.array(boxes)
    scores = np.array(scores)

    order = scores.argsort()[::-1]  # descent sort
    rst = []  # index results

    while order.shape[0] > 0:
        i = order[0]  # index of box with highest score
        rst.append(i)
        other_boxes = boxes[order[1:]]
        ious = [iou(boxes[i], box) for box in other_boxes]
        ious = np.array(ious)

        indexes = np.where(ious <= iou_th)[0]
        order = order[1 + indexes]
    return rst


if __name__ == "__main__":
    # img = cv2.imread(sys.path[0] + "/raw_img.png")
    boxes = [
        [183, 625, 269, 865],
        [197, 603, 296, 853],
        [190, 579, 295, 864],
        [537, 507, 618, 713],
        [535, 523, 606, 687],
    ]
    # img_box = img.copy()
    # for box in boxes:
    #     top_left = tuple(box[:2])
    #     bottom_right = tuple(box[2:])
    #     img_box = cv2.rectangle(img, top_left, bottom_right, (0, 0, 0), 2)  # 颜色黑色，线宽为2
    # cv2.imshow(img_box)
    scores = [0.7, 0.9, 0.95, 0.9, 0.6]
    iou_threshold = 0.5

    keep_indices = nms(boxes, scores, iou_threshold)
    print("保留的边界框索引:", keep_indices)
