#include <cstdint>

void merge(int32_t* array, int32_t* aux, uint32_t begin, uint32_t middle, uint32_t end)
{
  int left = begin;
  int right = middle;
  int temp = begin;

  // merge the left and right arrays until one runs out
  while((left <= middle - 1) && (right <= end))
  {
    if(array[left] <= array[right])
    {
      aux[temp] = array[left];
      left++;
    }
    else
    {
      aux[temp] = array[right];
      right++;
    }

    temp++;
  }

  // finish off any left array elements
  while(left <= middle - 1)
  {
    aux[temp] = array[left];
    temp++;
    left++;
  }

  // finish off any right array elements
  while(right <= end)
  {
    aux[temp] = array[right];
    temp++;
    right++;
  }

  // copy all sorted aux elements back into the original array
  // why do this from the end to begin? cache benefits?
  const uint32_t num_elements = end - begin + 1;
  for (uint32_t i = 0; i < num_elements; i++, end--)
  {
    array[end] = aux[end];
  }
}

void merge_sort(int32_t* array, int32_t* aux, uint32_t begin, uint32_t end)
{
  if (end <= begin) { return; }

  uint32_t middle = (begin + end) / 2;

  // front half
  merge_sort(array, aux, begin, middle);

  // back half
  merge_sort(array, aux, middle + 1, end);

  // merge the two together into the aux array
  merge(array, aux, begin, middle + 1, end);
}

